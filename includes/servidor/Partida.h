#ifndef _PARTIDA_H_
#define _PARTIDA_H_

#include "includes/common/Hilo.h"
#include "includes/common/Handler.h"
#include "includes/common/ColaProtegida.h"
#include "includes/servidor/Jugador.h"
#include "includes/servidor/modelo/Mundo.h"

#include <map>
#include <memory>

class Partida : public Hilo, public Handler {
private:
    std::map<uint32_t, std::shared_ptr<Jugador>> jugadores_;
    ColaProtegida<std::shared_ptr<Evento>> eventosEntrantes_;
    Mundo mundo_;

    Partida(const Partida& otra) = delete;
    Partida& operator=(const Partida& otra) = delete;

public:
    Partida(uint16_t uuidPista);
    ~Partida();

    void agregarJugador(std::shared_ptr<Jugador> jugador);

    virtual void correr() override;
    virtual void detener() override;

    void ocurrio(std::shared_ptr<Evento> unEvento);

    virtual void manejar(Evento& e) override;
    virtual void manejar(EventoAcelerar& e) override;
};

#endif
