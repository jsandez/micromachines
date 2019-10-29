#ifndef _SALA_DE_ESPERA_H_
#define _SALA_DE_ESPERA_H_

#include <map>
#include <memory>

#include "includes/common/red/SocketTCP.h"
#include "includes/servidor/red/Jugador.h"


class SalaDeEspera {
private:
    uint32_t contadorJugadores_;
    ColaBloqueante<std::shared_ptr<Evento>>& destinoEventos_;
    std::map<uint32_t, std::shared_ptr<Jugador>> jugadores_;

public:
    SalaDeEspera(ColaBloqueante<std::shared_ptr<Evento>>& destinoEventos);
    ~SalaDeEspera();
    void agregarJugador(SocketTCP&& socket, bool& seguirCorriendo);
};

#endif
