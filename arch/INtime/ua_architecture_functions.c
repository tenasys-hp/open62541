#ifdef UA_ARCHITECTURE_INTIME

#include <open62541/types.h>
#include <sys/ioctl.h>

/* Global malloc singletons */
#ifdef UA_ENABLE_MALLOC_SINGLETON
void *(*UA_mallocSingleton)(size_t size) = malloc;
void (*UA_freeSingleton)(void *ptr) = free;
void *(*UA_callocSingleton)(size_t nelem, size_t elsize) = calloc;
void *(*UA_reallocSingleton)(void *ptr, size_t size) = realloc;
#endif

inline unsigned int
UA_socket_set_blocking(UA_SOCKET sockfd) {
  u_long iMode = 0;
  if(ioctl(sockfd, FIONBIO, &iMode) < 0)
    return UA_STATUSCODE_BADINTERNALERROR;
  return UA_STATUSCODE_GOOD;
}

inline unsigned int
UA_socket_set_nonblocking(UA_SOCKET sockfd) {
  u_long iMode = 1;
  if(ioctl(sockfd, FIONBIO, &iMode) < 0)
    return UA_STATUSCODE_BADINTERNALERROR;
  return UA_STATUSCODE_GOOD;
}

inline void
UA_initialize_architecture_network(void) {
    return;
}

inline void
UA_deinitialize_architecture_network(void) {
    return;
}

#endif /* UA_ARCHITECTURE_INTIME */
