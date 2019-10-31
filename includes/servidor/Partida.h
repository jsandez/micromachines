#ifndef _PARTIDA_H_
#define _PARTIDA_H_

#include "includes/common/Hilo.h"
#include "includes/common/Handler.h"
#include "includes/common/ColaBloqueante.h"
#include "includes/servidor/Jugador.h"
#include "includes/servidor/modelo/Mundo.h"

#include <map>
#include <memory>

class Partida : public Hilo, public Handler {
private:
    std::map<uint32_t, std::shared_ptr<Jugador>> jugadores_;
    ColaBloqueante<std::shared_ptr<Evento>> eventosEntrantes_;
    Mundo mundo_;
    bool jugando_;
    bool& seguirCorriendo_;

    Partida(const Partida& otra) = delete;
    Partida& operator=(const Partida& otra) = delete;

public:
    Partida(bool& seguirCorriendo);
    ~Partida();

    void agregarJugador(std::shared_ptr<Jugador> jugador);

    virtual void run() override;
    virtual void manejar(Evento& e) override;
};

#endif
