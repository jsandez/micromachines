#ifndef _SALA_DE_ESPERA_H_
#define _SALA_DE_ESPERA_H_

#include <map>
#include <memory>

#include "includes/common/Handler.h"
#include "includes/common/red/SocketTCP.h"
#include "includes/servidor/Jugador.h"

class SalaDeEspera : public Handler {
private:
    uint32_t contadorJugadores_;
    ColaBloqueante<std::shared_ptr<Evento>>& destinoEventos_;
    //FIXME: Proteger esto
    std::map<uint32_t, std::shared_ptr<Jugador>> jugadores_;

public:
    SalaDeEspera(ColaBloqueante<std::shared_ptr<Evento>>& destinoEventos);
    ~SalaDeEspera();
    void agregarJugador(SocketTCP&& socket);
    std::shared_ptr<Jugador> obtenerJugador(uint32_t uuidJugador);
    virtual void manejar(Evento& e) override;
    virtual void manejar(EventoDesconexion& e) override;
};

#endif
