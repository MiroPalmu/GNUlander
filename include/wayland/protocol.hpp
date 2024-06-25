#pragma once

/// @file Contains stuff related to Wayland protocol

#include <cstdint>
#include <filesystem>
#include <vector>

#include "gnu_utils/local_stream_socket.hpp"
#include "wayland/message_buffer.hpp"
#include "wayland/message_parser.hpp"
#include "wayland/protocol_primitives.hpp"
#include "wayland/protocols/wayland_protocol.hpp"
#include "wayland/system_utils.hpp"

namespace ger {
namespace wl {

static constexpr auto global_display_object = Wobject<protocols::wl_display>{ 1 };

/// Represents one connected client by wrapping the Wayland socket.
class connected_client {
    gnu::local_stream_socket server_sock_;
    Wuint::integral_type next_new_id_{ 2 };
    message_buffer request_buff_{};
    /// Allways assumed that the data never begins at middle of message, only at a beginning.
    sstd::byte_vec recv_buff_{};

  public:
    /// Connected to socket at \p socket.
    [[nodiscard]] connected_client(const std::filesystem::path& socket = wayland_socket_path());

    /// Uses given \p socket as the compositor socket.
    [[nodiscard]] connected_client(gnu::local_stream_socket&& socket);

    template<typename T = generic_object>
    [[nodiscard]] auto reserve_object_id() -> Wobject<T> {
        return { next_new_id_++ };
    }

    template<interface WObj, message_for_inteface<WObj> request>
    void register_request(const Wobject<WObj> obj, const request& msg) {
        request_buff_.append(obj, msg);
    }

    void flush_registered_requests();

    [[nodiscard]] constexpr bool has_registered_requests(this auto&& self) noexcept {
        return not self.request_buff_.empty();
    }

    /// Receive non-zero amount of data to recv_buff_.
    void recv_more_data();

    /// Inspect recv_buff_ and get bytes from beginning that are checked to form whole messages.
    [[nodiscard]] auto get_recd_bytes_forming_whole_messages() -> std::span<const std::byte>;

    /// Read non-zero amount of bytes and return parser with all whole messages received.
    [[nodiscard]] auto recv_events() -> message_parser;
};

} // namespace wl
} // namespace ger
