#ifdef UA_ARCHITECTURE_INTIME

#ifndef PLUGINS_ARCH_INTIME_UA_ARCHITECTURE_H_
#define PLUGINS_ARCH_INTIME_UA_ARCHITECTURE_H_

#ifndef __INTIME__
#define __INTIME__
#endif

#ifndef __C99__
#define __C99__
#endif

// INtime does not support alloca
// That will override the one in the generic header.
#define UA_STACKARRAY(TYPE, NAME, SIZE) TYPE NAME[SIZE]

#include <open62541/architecture_definitions.h>

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <iwin32.h>
#include <rt.h>

#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define ssize_t int
#define OPTVAL_TYPE char

#define UA_sleep_ms(X)  \
{                       \
    RtSleepEx(X);       \
}

// INtime does not support ansi colors
// #define UA_ENABLE_LOG_COLORS

#define UA_IPV6 1

# define UA_SOCKET SOCKET
# define UA_INVALID_SOCKET INVALID_SOCKET

#define UA_ERRNO GetLastRtError()
#define UA_INTERRUPTED WSAEINTR
#define UA_AGAIN WSAEWOULDBLOCK
#define UA_EAGAIN EAGAIN
#define UA_WOULDBLOCK WSAEWOULDBLOCK
#define UA_ERR_CONNECTION_PROGRESS WSAEWOULDBLOCK

#define UA_fd_set(fd, fds) FD_SET((UA_SOCKET)fd, fds)
#define UA_fd_isset(fd, fds) FD_ISSET((UA_SOCKET)fd, fds)

#ifdef UNDER_CE
# define errno
#endif

#define UA_getnameinfo getnameinfo
#define UA_send(sockfd, buf, len, flags) send(sockfd, buf, (int)(len), flags)
#define UA_recv(sockfd, buf, len, flags) recv(sockfd, buf, (int)(len), flags)
#define UA_sendto(sockfd, buf, len, flags, dest_addr, addrlen) sendto(sockfd, (const char*)(buf), (int)(len), flags, dest_addr, (int) (addrlen))
#define UA_recvfrom(sockfd, buf, len, flags, src_addr, addrlen) recvfrom(sockfd, (char*)(buf), (int)(len), flags, src_addr, addrlen)
#define UA_htonl htonl
#define UA_ntohl ntohl
#define UA_close closesocket
#define UA_select(nfds, readfds, writefds, exceptfds, timeout) select((int)(nfds), readfds, writefds, exceptfds, timeout)
#define UA_shutdown shutdown
#define UA_socket socket
#define UA_bind bind
#define UA_listen listen
#define UA_accept accept
#define UA_connect(sockfd, addr, addrlen) connect(sockfd, addr, (int)(addrlen))
#define UA_getaddrinfo getaddrinfo
#define UA_getsockopt getsockopt
#define UA_setsockopt(sockfd, level, optname, optval, optlen) setsockopt(sockfd, level, optname, (const char*) (optval), optlen)
#define UA_freeaddrinfo freeaddrinfo
#define UA_gethostname gethostname
#define UA_getsockname getsockname
#define UA_inet_pton inet_pton

#if UA_IPV6
# define UA_if_nametoindex if_nametoindex
#endif

#ifdef maxStringLength //defined in mingw64
# undef maxStringLength
#endif

/* Use the standard malloc */
#ifndef UA_free
# define UA_free free
# define UA_malloc malloc
# define UA_calloc calloc
# define UA_realloc realloc
#endif

/* 3rd Argument is the string */
#define UA_snprintf(source, size, ...) _snprintf_s(source, size, _TRUNCATE, __VA_ARGS__)
#define UA_strncasecmp _strnicmp

#define UA_LOG_SOCKET_ERRNO_WRAP(LOG) { \
    char *errno_str = strerror(errno); \
    LOG; \
}
#define UA_LOG_SOCKET_ERRNO_GAI_WRAP UA_LOG_SOCKET_ERRNO_WRAP

// INtime does not support multi thread
// #define UA_MULTITHREADING
#if 1
#define UA_LOCK_INIT(lock)
#define UA_LOCK_DESTROY(lock)
#define UA_LOCK(lock)
#define UA_UNLOCK(lock)
#define UA_LOCK_ASSERT(lock, num)
#endif

#include <open62541/architecture_functions.h>

#endif /* PLUGINS_ARCH_INTIME_UA_ARCHITECTURE_H_ */

#endif /* UA_ARCHITECTURE_INTIME */
