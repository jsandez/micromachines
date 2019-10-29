#ifndef _PROTOCOLO_H_
#define _PROTOCOLO_H_

#include "includes/common/red/SocketTCP.h"

#define LEN_8 1
#define LEN_16 2
#define LEN_32 4

class Protocolo {
private:
    SocketTCP& socket_;
public:
    Protocolo(SocketTCP& socket);
    uint16_t recibirNumUnsigned16();
};

#endif
