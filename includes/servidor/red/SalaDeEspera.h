#ifndef _SALA_DE_ESPERA_H_
#define _SALA_DE_ESPERA_H_

#include <map>

#include "includes/common/red/SocketTCP.h"
#include "includes/servidor/red/Jugador.h"


class SalaDeEspera {
private:
    //bool& seguirCorriendo_;
    //CoordinadorPartidas coordinadorPartidas_;
    std::map<unsigned int, Jugador> jugadores_;
    //ColaBloqueante<std::shared_ptr<Evento>> eventosEntrantes_;

public:
    void agregarJugador(SocketTCP&& socket);
};

#endif
