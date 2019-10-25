#ifndef _SOCKET_TCP_H_
#define _SOCKET_TCP_H_

#include <cstddef>
#include <netdb.h>

class SocketTCP {
protected:
    int fileDescripor_;
    addrinfo* hints_;

public:
    int enviarN(const char* buffer, size_t nBytes);
    int recibirN(char* buffer, size_t nBytes);
};

#endif
