#ifndef _SERVIDOR_H_
#define _SERVIDOR_H_

#include "includes/servidor/red/SocketTCPServidor.h"

#include <string>

class Servidor {
private:
    SocketTCPServidor sktAceptador_;

public:
    Servidor(const std::string& puerto);
    void correr();
};

#endif
