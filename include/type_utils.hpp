#pragma once

#include <concepts>
#include <functional>
#include <tuple>
#include <type_traits>
#include <utility>

namespace ger {
namespace sstd {

/// Used to instantiate template template parameters to get infromation about the template template.
struct probe_type {
    template<class T>
    constexpr operator T(); // non explicit
};

template<template<typename> typename Trait>
concept unary_predicate_trait = std::derived_from<Trait<probe_type>, std::bool_constant<true>>
                                or std::derived_from<Trait<probe_type>, std::bool_constant<false>>;

/// Satisfied if type trait Trait is satisfied for all types T... .
template<template<typename> typename Trait, typename... T>
concept unary_predicate_trait_fold = unary_predicate_trait<Trait> and (Trait<T>::value && ...);

/// Helper for visitor patter to create overloaded function objects.
template<class... Ts>
struct overloaded : Ts... { using Ts::operator()...; };

/// Returns std::tuple<const T&...> where T... are the elements of \p t.
template<typename T>
    requires(std::is_aggregate_v<std::remove_cvref_t<T>>)
constexpr auto to_ref_tuple(const T& t) {
    if constexpr (std::constructible_from<T,
                                          probe_type,
                                          probe_type,
                                          probe_type,
                                          probe_type,
                                          probe_type,
                                          probe_type,
                                          probe_type,
                                          probe_type,
                                          probe_type,
                                          probe_type,
                                          probe_type,
                                          probe_type,
                                          probe_type,
                                          probe_type,
                                          probe_type,
                                          probe_type,
                                          probe_type,
                                          probe_type,
                                          probe_type,
                                          probe_type>) {
        const auto& [x20,
                     x19,
                     x18,
                     x17,
                     x16,
                     x15,
                     x14,
                     x13,
                     x12,
                     x11,
                     x10,
                     x9,
                     x8,
                     x7,
                     x6,
                     x5,
                     x4,
                     x3,
                     x2,
                     x1] = t;
        return std::make_tuple(std::cref(x20),
                               std::cref(x19),
                               std::cref(x18),
                               std::cref(x17),
                               std::cref(x16),
                               std::cref(x15),
                               std::cref(x14),
                               std::cref(x13),
                               std::cref(x12),
                               std::cref(x11),
                               std::cref(x10),
                               std::cref(x9),
                               std::cref(x8),
                               std::cref(x7),
                               std::cref(x6),
                               std::cref(x5),
                               std::cref(x4),
                               std::cref(x3),
                               std::cref(x2),
                               std::cref(x1));
    } else if constexpr (std::constructible_from<T,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type>) {
        const auto& [x19,
                     x18,
                     x17,
                     x16,
                     x15,
                     x14,
                     x13,
                     x12,
                     x11,
                     x10,
                     x9,
                     x8,
                     x7,
                     x6,
                     x5,
                     x4,
                     x3,
                     x2,
                     x1] = t;
        return std::make_tuple(std::cref(x19),
                               std::cref(x18),
                               std::cref(x17),
                               std::cref(x16),
                               std::cref(x15),
                               std::cref(x14),
                               std::cref(x13),
                               std::cref(x12),
                               std::cref(x11),
                               std::cref(x10),
                               std::cref(x9),
                               std::cref(x8),
                               std::cref(x7),
                               std::cref(x6),
                               std::cref(x5),
                               std::cref(x4),
                               std::cref(x3),
                               std::cref(x2),
                               std::cref(x1));
    } else if constexpr (std::constructible_from<T,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type>) {
        const auto& [x18,
                     x17,
                     x16,
                     x15,
                     x14,
                     x13,
                     x12,
                     x11,
                     x10,
                     x9,
                     x8,
                     x7,
                     x6,
                     x5,
                     x4,
                     x3,
                     x2,
                     x1] = t;
        return std::make_tuple(std::cref(x18),
                               std::cref(x17),
                               std::cref(x16),
                               std::cref(x15),
                               std::cref(x14),
                               std::cref(x13),
                               std::cref(x12),
                               std::cref(x11),
                               std::cref(x10),
                               std::cref(x9),
                               std::cref(x8),
                               std::cref(x7),
                               std::cref(x6),
                               std::cref(x5),
                               std::cref(x4),
                               std::cref(x3),
                               std::cref(x2),
                               std::cref(x1));
    } else if constexpr (std::constructible_from<T,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type>) {
        const auto& [x17, x16, x15, x14, x13, x12, x11, x10, x9, x8, x7, x6, x5, x4, x3, x2, x1] =
            t;
        return std::make_tuple(std::cref(x17),
                               std::cref(x16),
                               std::cref(x15),
                               std::cref(x14),
                               std::cref(x13),
                               std::cref(x12),
                               std::cref(x11),
                               std::cref(x10),
                               std::cref(x9),
                               std::cref(x8),
                               std::cref(x7),
                               std::cref(x6),
                               std::cref(x5),
                               std::cref(x4),
                               std::cref(x3),
                               std::cref(x2),
                               std::cref(x1));
    } else if constexpr (std::constructible_from<T,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type>) {
        const auto& [x16, x15, x14, x13, x12, x11, x10, x9, x8, x7, x6, x5, x4, x3, x2, x1] = t;
        return std::make_tuple(std::cref(x16),
                               std::cref(x15),
                               std::cref(x14),
                               std::cref(x13),
                               std::cref(x12),
                               std::cref(x11),
                               std::cref(x10),
                               std::cref(x9),
                               std::cref(x8),
                               std::cref(x7),
                               std::cref(x6),
                               std::cref(x5),
                               std::cref(x4),
                               std::cref(x3),
                               std::cref(x2),
                               std::cref(x1));
    } else if constexpr (std::constructible_from<T,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type>) {
        const auto& [x15, x14, x13, x12, x11, x10, x9, x8, x7, x6, x5, x4, x3, x2, x1] = t;
        return std::make_tuple(std::cref(x15),
                               std::cref(x14),
                               std::cref(x13),
                               std::cref(x12),
                               std::cref(x11),
                               std::cref(x10),
                               std::cref(x9),
                               std::cref(x8),
                               std::cref(x7),
                               std::cref(x6),
                               std::cref(x5),
                               std::cref(x4),
                               std::cref(x3),
                               std::cref(x2),
                               std::cref(x1));
    } else if constexpr (std::constructible_from<T,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type>) {
        const auto& [x14, x13, x12, x11, x10, x9, x8, x7, x6, x5, x4, x3, x2, x1] = t;
        return std::make_tuple(std::cref(x14),
                               std::cref(x13),
                               std::cref(x12),
                               std::cref(x11),
                               std::cref(x10),
                               std::cref(x9),
                               std::cref(x8),
                               std::cref(x7),
                               std::cref(x6),
                               std::cref(x5),
                               std::cref(x4),
                               std::cref(x3),
                               std::cref(x2),
                               std::cref(x1));
    } else if constexpr (std::constructible_from<T,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type>) {
        const auto& [x13, x12, x11, x10, x9, x8, x7, x6, x5, x4, x3, x2, x1] = t;
        return std::make_tuple(std::cref(x13),
                               std::cref(x12),
                               std::cref(x11),
                               std::cref(x10),
                               std::cref(x9),
                               std::cref(x8),
                               std::cref(x7),
                               std::cref(x6),
                               std::cref(x5),
                               std::cref(x4),
                               std::cref(x3),
                               std::cref(x2),
                               std::cref(x1));
    } else if constexpr (std::constructible_from<T,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type>) {
        const auto& [x12, x11, x10, x9, x8, x7, x6, x5, x4, x3, x2, x1] = t;
        return std::make_tuple(std::cref(x12),
                               std::cref(x11),
                               std::cref(x10),
                               std::cref(x9),
                               std::cref(x8),
                               std::cref(x7),
                               std::cref(x6),
                               std::cref(x5),
                               std::cref(x4),
                               std::cref(x3),
                               std::cref(x2),
                               std::cref(x1));
    } else if constexpr (std::constructible_from<T,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type>) {
        const auto& [x11, x10, x9, x8, x7, x6, x5, x4, x3, x2, x1] = t;
        return std::make_tuple(std::cref(x11),
                               std::cref(x10),
                               std::cref(x9),
                               std::cref(x8),
                               std::cref(x7),
                               std::cref(x6),
                               std::cref(x5),
                               std::cref(x4),
                               std::cref(x3),
                               std::cref(x2),
                               std::cref(x1));
    } else if constexpr (std::constructible_from<T,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type>) {
        const auto& [x10, x9, x8, x7, x6, x5, x4, x3, x2, x1] = t;
        return std::make_tuple(std::cref(x10),
                               std::cref(x9),
                               std::cref(x8),
                               std::cref(x7),
                               std::cref(x6),
                               std::cref(x5),
                               std::cref(x4),
                               std::cref(x3),
                               std::cref(x2),
                               std::cref(x1));
    } else if constexpr (std::constructible_from<T,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type>) {
        const auto& [x9, x8, x7, x6, x5, x4, x3, x2, x1] = t;
        return std::make_tuple(std::cref(x9),
                               std::cref(x8),
                               std::cref(x7),
                               std::cref(x6),
                               std::cref(x5),
                               std::cref(x4),
                               std::cref(x3),
                               std::cref(x2),
                               std::cref(x1));
    } else if constexpr (std::constructible_from<T,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type>) {
        const auto& [x8, x7, x6, x5, x4, x3, x2, x1] = t;
        return std::make_tuple(std::cref(x8),
                               std::cref(x7),
                               std::cref(x6),
                               std::cref(x5),
                               std::cref(x4),
                               std::cref(x3),
                               std::cref(x2),
                               std::cref(x1));
    } else if constexpr (std::constructible_from<T,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type>) {
        const auto& [x7, x6, x5, x4, x3, x2, x1] = t;
        return std::make_tuple(std::cref(x7),
                               std::cref(x6),
                               std::cref(x5),
                               std::cref(x4),
                               std::cref(x3),
                               std::cref(x2),
                               std::cref(x1));
    } else if constexpr (std::constructible_from<T,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type,
                                                 probe_type>) {
        const auto& [x6, x5, x4, x3, x2, x1] = t;
        return std::make_tuple(std::cref(x6),
                               std::cref(x5),
                               std::cref(x4),
                               std::cref(x3),
                               std::cref(x2),
                               std::cref(x1));
    } else if constexpr (
        std::constructible_from<T, probe_type, probe_type, probe_type, probe_type, probe_type>) {
        const auto& [x5, x4, x3, x2, x1] = t;
        return std::make_tuple(std::cref(x5),
                               std::cref(x4),
                               std::cref(x3),
                               std::cref(x2),
                               std::cref(x1));
    } else if constexpr (
        std::constructible_from<T, probe_type, probe_type, probe_type, probe_type>) {
        const auto& [x4, x3, x2, x1] = t;
        return std::make_tuple(std::cref(x4), std::cref(x3), std::cref(x2), std::cref(x1));
    } else if constexpr (std::constructible_from<T, probe_type, probe_type, probe_type>) {
        const auto& [x3, x2, x1] = t;
        return std::make_tuple(std::cref(x3), std::cref(x2), std::cref(x1));
    } else if constexpr (std::constructible_from<T, probe_type, probe_type>) {
        const auto& [x2, x1] = t;
        return std::make_tuple(std::cref(x2), std::cref(x1));
    } else if constexpr (std::constructible_from<T, probe_type>) {
        const auto& [x1] = t;
        return std::make_tuple(std::cref(x1));
    } else {
        static_assert(false, "Waiting room for reflection...");
    }
}

} // namespace sstd
} // namespace ger
