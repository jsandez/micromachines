#ifndef _PROTOCOLO_H_
#define _PROTOCOLO_H_

#include "includes/common/red/SocketTCP.h"

class Protocolo {
private:
    SocketTCP& socket_;
public:
    Protocolo(SocketTCP& socket);
};

#endif
