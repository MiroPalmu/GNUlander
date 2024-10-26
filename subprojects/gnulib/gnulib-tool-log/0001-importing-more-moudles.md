# Importing rest of documented modules #1

```bash
=> ~/data/scratch/repos/gnulib/gnulib-tool --add-import full-read full-write pipe2-safer mkfifo socket connect open close
Module list with included dependencies (indented):
    absolute-header
    alignasof
    alloca-opt
    assert-h
    binary-io
    c99
    cloexec
  close
  connect
    dup2
    errno
    extensions
    extern-inline
    fcntl
    fcntl-h
    fd-hook
    fd-safer-flag
    filename
    fstat
  full-read
  full-write
    gen-header
    getdtablesize
    idx
    include_next
    largefile
    limits-h
    malloca
  mkfifo
    msvc-inval
    msvc-nothrow
    multiarch
  open
    pathmax
    pipe-posix
    pipe2
  pipe2-safer
    raise
    read
    safe-read
    safe-write
    signal-h
    snippet/arg-nonnull
    snippet/c++defs
    snippet/warn-on-use
  socket
    socketlib
    sockets
    socklen
    ssize_t
    stat
    stat-time
    std-gnu11
    stdbool
    stdckdint
    stddef
    stdint
    sys_socket
    sys_stat
    sys_types
    sys_uio
    time-h
    unistd
    unistd-safer
    write
    xalloc-oversized
File list:
  lib/alloca.in.h
  lib/arg-nonnull.h
  lib/assert.in.h
  lib/binary-io.c
  lib/binary-io.h
  lib/c++defs.h
  lib/cloexec.c
  lib/cloexec.h
  lib/close.c
  lib/connect.c
  lib/dup-safer-flag.c
  lib/dup-safer.c
  lib/dup2.c
  lib/errno.in.h
  lib/fcntl.c
  lib/fcntl.in.h
  lib/fd-hook.c
  lib/fd-hook.h
  lib/fd-safer-flag.c
  lib/fd-safer.c
  lib/filename.h
  lib/fstat.c
  lib/full-read.c
  lib/full-read.h
  lib/full-write.c
  lib/full-write.h
  lib/getdtablesize.c
  lib/idx.h
  lib/intprops-internal.h
  lib/limits.in.h
  lib/malloca.c
  lib/malloca.h
  lib/mkfifo.c
  lib/msvc-inval.c
  lib/msvc-inval.h
  lib/msvc-nothrow.c
  lib/msvc-nothrow.h
  lib/open.c
  lib/pathmax.h
  lib/pipe-safer.c
  lib/pipe.c
  lib/pipe2-safer.c
  lib/pipe2.c
  lib/raise.c
  lib/read.c
  lib/safe-read.c
  lib/safe-read.h
  lib/safe-write.c
  lib/safe-write.h
  lib/signal.in.h
  lib/socket.c
  lib/sockets.c
  lib/sockets.h
  lib/stat-time.c
  lib/stat-time.h
  lib/stat-w32.c
  lib/stat-w32.h
  lib/stat.c
  lib/stdckdint.in.h
  lib/stddef.in.h
  lib/stdint.in.h
  lib/sys-limits.h
  lib/sys_socket.c
  lib/sys_socket.in.h
  lib/sys_stat.in.h
  lib/sys_types.in.h
  lib/sys_uio.in.h
  lib/time.in.h
  lib/unistd--.h
  lib/unistd-safer.h
  lib/unistd.c
  lib/unistd.in.h
  lib/verify.h
  lib/w32sock.h
  lib/warn-on-use.h
  lib/write.c
  lib/xalloc-oversized.h
  m4/00gnulib.m4
  m4/absolute-header.m4
  m4/alloca.m4
  m4/assert_h.m4
  m4/c-bool.m4
  m4/close.m4
  m4/dup2.m4
  m4/eealloc.m4
  m4/errno_h.m4
  m4/extensions.m4
  m4/extern-inline.m4
  m4/fcntl-o.m4
  m4/fcntl.m4
  m4/fcntl_h.m4
  m4/fstat.m4
  m4/getdtablesize.m4
  m4/gnulib-common.m4
  m4/include_next.m4
  m4/largefile.m4
  m4/limits-h.m4
  m4/malloca.m4
  m4/mkfifo.m4
  m4/mode_t.m4
  m4/msvc-inval.m4
  m4/msvc-nothrow.m4
  m4/multiarch.m4
  m4/off_t.m4
  m4/open-cloexec.m4
  m4/open-slash.m4
  m4/open.m4
  m4/pathmax.m4
  m4/pid_t.m4
  m4/pipe.m4
  m4/pipe2.m4
  m4/raise.m4
  m4/read.m4
  m4/safe-read.m4
  m4/safe-write.m4
  m4/signal_h.m4
  m4/socketlib.m4
  m4/sockets.m4
  m4/socklen.m4
  m4/sockpfaf.m4
  m4/ssize_t.m4
  m4/stat-time.m4
  m4/stat.m4
  m4/std-gnu11.m4
  m4/stdalign.m4
  m4/stddef_h.m4
  m4/stdint.m4
  m4/sys_socket_h.m4
  m4/sys_stat_h.m4
  m4/sys_types_h.m4
  m4/sys_uio_h.m4
  m4/time_h.m4
  m4/unistd-safer.m4
  m4/unistd_h.m4
  m4/warn-on-use.m4
  m4/wchar_t.m4
  m4/wint_t.m4
  m4/write.m4
  m4/zzgnulib.m4
Copying file lib/alloca.in.h
Copying file lib/connect.c
Copying file lib/errno.in.h
Copying file lib/filename.h
Copying file lib/fstat.c
Copying file lib/idx.h
Copying file lib/intprops-internal.h
Copying file lib/limits.in.h
Copying file lib/malloca.c
Copying file lib/malloca.h
Copying file lib/mkfifo.c
Copying file lib/open.c
Copying file lib/pathmax.h
Copying file lib/socket.c
Copying file lib/sockets.c
Copying file lib/sockets.h
Copying file lib/stat-time.c
Copying file lib/stat-time.h
Copying file lib/stat-w32.c
Copying file lib/stat-w32.h
Copying file lib/stat.c
Copying file lib/stdckdint.in.h
Copying file lib/stdint.in.h
Copying file lib/sys_socket.c
Copying file lib/sys_socket.in.h
Copying file lib/sys_stat.in.h
Copying file lib/sys_uio.in.h
Copying file lib/time.in.h
Copying file lib/w32sock.h
Copying file lib/xalloc-oversized.h
Copying file m4/alloca.m4
Copying file m4/eealloc.m4
Copying file m4/errno_h.m4
Copying file m4/fstat.m4
Copying file m4/largefile.m4
Copying file m4/limits-h.m4
Copying file m4/malloca.m4
Copying file m4/mkfifo.m4
Copying file m4/mode_t.m4
Copying file m4/multiarch.m4
Copying file m4/open-cloexec.m4
Copying file m4/open-slash.m4
Copying file m4/open.m4
Copying file m4/pathmax.m4
Copying file m4/socketlib.m4
Copying file m4/sockets.m4
Copying file m4/socklen.m4
Copying file m4/sockpfaf.m4
Copying file m4/stat-time.m4
Copying file m4/stat.m4
Copying file m4/stdalign.m4
Copying file m4/stdint.m4
Copying file m4/sys_socket_h.m4
Copying file m4/sys_stat_h.m4
Copying file m4/sys_uio_h.m4
Copying file m4/time_h.m4
Copying file m4/wint_t.m4
Updating m4/gnulib-cache.m4 (backup in m4/gnulib-cache.m4~)
Updating m4/gnulib-comp.m4 (backup in m4/gnulib-comp.m4~)
Updating lib/Makefile.am (backup in lib/Makefile.am~)
Finished.

You may need to add #include directives for the following .h files.
  #include <fcntl.h>
  #include <sys/socket.h>
  #include <sys/stat.h>
  #include <unistd.h>
  #include "full-read.h"
  #include "full-write.h"
  #include "unistd-safer.h"

You may need to use the following Makefile variables when linking.
Use them in <program>_LDADD when linking a program, or
in <library>_a_LDFLAGS or <library>_la_LDFLAGS when linking a library.
  $(LIBSOCKET)

Don't forget to
  - add "lib/Makefile" to AC_CONFIG_FILES in ./configure.ac,
  - mention "lib" in SUBDIRS in Makefile.am,
  - mention "-I m4" in ACLOCAL_AMFLAGS in Makefile.am
    or add an AC_CONFIG_MACRO_DIRS([m4]) invocation in ./configure.ac,
  - mention "m4/gnulib-cache.m4" in EXTRA_DIST in Makefile.am,
  - invoke gl_EARLY in ./configure.ac, right after AC_PROG_CC,
```
