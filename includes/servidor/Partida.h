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
//TODO: Devolver al jugador a la sala de espera cuando finaliza la partida
private:
    std::map<uint32_t, std::shared_ptr<Jugador>> jugadores_;
    std::map<uint32_t, bool> uuidJugadorAEstaListo_;
    ColaProtegida<std::shared_ptr<Evento>> eventosEntrantes_;
    Mundo mundo_;

    Partida(const Partida& otra) = delete;
    Partida& operator=(const Partida& otra) = delete;

    void step(uint32_t iteracion);
    void asignarVehiculos();

public:
    Partida(uint16_t uuidPista);
    ~Partida();

    void agregarJugador(std::shared_ptr<Jugador> jugador);
    std::map<uint32_t, std::shared_ptr<Jugador>>& jugadores();

    bool todosListos();
    void estaListo(uint32_t uuidJugador);

    virtual void correr() override;
    virtual void detener() override;

    virtual void manejar(Evento& e) override;
    virtual void manejar(EventoFinCarrera& e) override;

    void ocurrio(std::shared_ptr<Evento> unEvento);
};

#endif
