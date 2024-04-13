#pragma once

#include <cstddef>
#include <span>
#include <tuple>

namespace ger {
namespace gnu {

using fd_native_type             = int;
static constexpr auto invalid_fd = fd_native_type{ -1 };

/// Throwing wrapper for executing system calls on file descriptor.
///
/// Does not...
///     - ...own any system resources
///     - ...implement raii semantics
///     - ...validate contained fd_native_type before calls
///     - ...have any invariants
///
/// Following flags are cleared by default:
///     - O_CLOEXEC
///     - O_NONBLOCK
///
/// At the moment there is no facilities implemented to enable any of the flags above,
/// nor it is a priority goal.
class fd_handle {
    fd_native_type fd_{ invalid_fd };

    fd_handle(const fd_native_type fd);

  public:
    /// Blocking write.
    ///
    /// Writes data specified by \p what_to_write to fd.
    ///
    /// Keeps retrying if partial write happens or if writing is interrupted by signal (EINTR).
    ///
    /// Throws excpetion in case of error. Note that despite retrying efforts,
    /// partial writes might still occure, as error can happen during retry
    /// after partial write, which leads to exception and not continuation of retries.
    void write(const std::span<const std::byte> what_to_write);

    /// Blocking read.
    ///
    /// Writes data read from fd to memory specified by \p where_to_read,
    /// until it is full or EOF is encountered. Returns amount of bytes read.
    ///
    /// Keeps retrying if partial read happens or if reading is interrupted by signal (EINTR),
    /// until all asked bytes are read or EOF in encountered, which is indicated
    /// by returned amount of read bytes being less than what was requested.
    ///
    /// Throws excpetion in case of error. Note that despite retrying efforts,
    /// partial reads might still occure, as error can happen during retry
    /// after partial read, which leads to exception and not continuation of retries.
    [[nodiscard]] auto read(const std::span<std::byte> where_to_read) -> std::size_t;

    /// Opens posix pipe (i.e. file descriptor IN for reading and OUT for writing).
    ///
    /// From returned tuple fd_handle at index 0 is the read end of the pipe (IN) and
    /// fd_handle at index 1 is the write end of the pipe (OUT).
    ///
    ///     > An easy way to remember that the input end comes first is that
    ///     > file descriptor 0 is standard input,
    ///     > and file descriptor 1 is standard output
    ///                                           GNU libc manual 15.1 Creating a Pipe
    ///
    /// Ensures that neither of the file descriptors is stdin(0), stdout(1) nor stderr(2).
    /// This perevents accidental globbing of them when for variaty of reasons they
    /// might be closed and new file descriptors are allocated to "the smallest non-negative
    /// integer that does not yet correspond to an open file descriptor".
    ///
    /// This is achived by using gnulib module pipe2-safer.
    /// For more information see gnulib manual 17.10 Handling closed standard file descriptors.
    ///
    /// Setting flags (importantly O_CLOEXEC) is generally not atomic with opening of the pipe.
    /// This matters in multi-threaded programs that spawn child processes.
    /// See gnulib manual 13.116.24 pipe2 for more information.
    friend auto pipe() -> std::tuple<fd_handle, fd_handle>;

    /// Closes the file descriptor.
    ///
    /// Throws if closing failed due to error.
    void close();

    /// As fd_handle does not own any system resources, dtor does nothing.
    ~fd_handle() = default;

    // Moveable:
    fd_handle(fd_handle&& rhs);
    fd_handle& operator=(fd_handle&& rhs);
    // Not copyable:
    fd_handle(const fd_handle&)            = delete;
    fd_handle& operator=(const fd_handle&) = delete;
};

} // namespace gnu
} // namespace ger