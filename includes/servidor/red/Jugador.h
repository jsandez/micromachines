#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#include "includes/common/red/SocketTCP.h"

class Jugador {
private:
    SocketTCP socket_;
    ColaBloqueante<> eventosRecibidos_;
    ColaBloqueante<> eventosAEnviar_;

public:
    Jugador(SocketTCP&& socket);
};

#endif
