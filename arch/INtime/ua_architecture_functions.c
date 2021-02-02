#ifdef UA_ARCHITECTURE_INTIME

#include <open62541/types.h>
#include <sys/ioctl.h>

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
