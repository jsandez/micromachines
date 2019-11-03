#ifndef _COORDINADOR_PARTIDAS_H_
#define _COORDINADOR_PARTIDAS_H_

#include <map>
#include <memory>

#include "includes/servidor/Partida.h"
#include "includes/servidor/SalaDeEspera.h"
#include "includes/common/Handler.h"

class CoordinadorPartidas : public Handler{
private:
    uint16_t contadorPartidas_;
    SalaDeEspera& salaDeEspera_;
    std::map<uint16_t, std::shared_ptr<Partida>> partidas_;

public:
    CoordinadorPartidas(SalaDeEspera& salaDeEspera);
    ~CoordinadorPartidas();

    void agregarJugadorAPartida(std::shared_ptr<Jugador> jugador, uint16_t uuidPartida);

    virtual void manejar(Evento& e) override;
    virtual void manejar(EventoCrearPartida& e) override;
    virtual void manejar(EventoIniciarPartida& e) override;
    virtual void manejar(EventoDesconexion& e) override;
};

#endif
