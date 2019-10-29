#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#include <memory>

#include "includes/common/red/SocketTCP.h"
#include "includes/common/ColaBloqueante.h"
#include "includes/common/eventos/Evento.h"
#include "includes/common/RecibidorEventos.h"

class Jugador {
private:
    uint32_t UUID_;
    SocketTCP socket_;
    ColaBloqueante<std::shared_ptr<Evento>> eventosRecibidos_;
    ColaBloqueante<std::shared_ptr<Evento>> eventosAEnviar_;
    RecibidorEventos recibidorEventos_;
    

public:
    Jugador(SocketTCP&& socket, uint32_t uuid, bool& seguirCorriendo);
};

#endif
