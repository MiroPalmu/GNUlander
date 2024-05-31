#pragma once

/// @file Utilities for handling Wayland messages.

#include <concepts>
#include <type_traits>
#include <utility>

#include "sstd.hpp"
#include "type_utils.hpp"
#include "wayland/protocol_primitives.hpp"

namespace ger {
namespace wl {

namespace {
template<typename>
struct is_any_Wobject : std::false_type {};
template<interface WObj>
struct is_any_Wobject<Wobject<WObj>> : std::true_type {};

template<typename>
struct is_any_Wnew_id : std::false_type {};
template<interface WObj>
struct is_any_Wnew_id<Wnew_id<WObj>> : std::true_type {};

template<typename A>
concept enum_message_argument =
    std::is_enum_v<A>
    and (std::same_as<sstd::underlying_integral_t<Wint>, std::underlying_type_t<A>>
         or std::same_as<sstd::underlying_integral_t<Wuint>, std::underlying_type_t<A>>);
} // namespace

template<typename A>
concept static_message_argument =
    std::same_as<A, Wint> or std::same_as<A, Wuint> or std::same_as<A, Wfixed>
    or is_any_Wobject<A>::value or is_any_Wnew_id<A>::value or enum_message_argument<A>;

template<typename A>
concept dynamic_message_argument =
    std::same_as<A, Wstring> or std::same_as<A, Warray> or std::same_as<A, Wfd>;

template<typename Wmsg>
using message_args_to_tuple =
    sstd::steal_template_args_t<decltype(sstd::to_tuple(std::declval<Wmsg>())), sstd::type_list>;

template<typename Wmsg>
using message_args_to_type_list =
    sstd::steal_template_args_t<message_args_to_tuple<Wmsg>, sstd::type_list>;

template<typename Wmsg>
concept static_message =
    (sstd::template_invoke_with_list_t<std::conjunction,
                                       typename message_args_to_type_list<Wmsg>::template map<
                                           decltype([](static_message_argument auto) {
                                               return std::integral_constant<bool, true>{};
                                           }),
                                           decltype([](dynamic_message_argument auto) {
                                               return std::integral_constant<bool, false>{};
                                           })>>::value);

/// Calculates message size without the header in bytes.
template<static_message Wmsg>
constexpr auto message_payload_size(const Wmsg&) -> std::size_t {
    using size_of = decltype([]<typename T>(T) { return sstd::numeral_t<sizeof(T)>{}; });
    using add_op  = decltype([](auto Lhs, auto Rhs) {
        return sstd::numeral_t<decltype(Lhs)::value + decltype(Rhs)::value>{};
    });

    return message_args_to_type_list<Wmsg>::template map<
        size_of>::template fold_left<sstd::numeral_t<0uz>, add_op>::value;
}

} // namespace wl
} // namespace ger
