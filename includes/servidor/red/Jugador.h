#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#include <memory>

#include "includes/common/red/SocketTCP.h"
#include "includes/common/ColaBloqueante.h"
#include "includes/common/eventos/Evento.h"

class Jugador {
private:
    SocketTCP socket_;
    ColaBloqueante<std::shared_ptr<Evento>> eventosRecibidos_;
    ColaBloqueante<std::shared_ptr<Evento>> eventosAEnviar_;
    

public:
    Jugador(SocketTCP&& socket);
};

#endif
