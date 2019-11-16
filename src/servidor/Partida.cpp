#include "includes/servidor/Partida.h"

#include <cmath>
#include <thread>
#include <chrono>

#include "includes/common/Cronometro.h"
#include "includes/common/Cola.h"
#include "includes/servidor/utils/ConfigServidor.h"
#include "includes/common/eventos/EventoIDVehiculoDeJugador.h"

Partida::Partida(uint16_t uuidPista) :
    mundo_(uuidPista) {
}

Partida::~Partida() {
}

void Partida::agregarJugador(std::shared_ptr<Jugador> jugador) {
    jugadores_[jugador->uuid()] = jugador;
}

void Partida::step(uint32_t nroIteracion) {
    bool obtenido = false;
    std::shared_ptr<Evento> evento;
    while((obtenido = eventosEntrantes_.get(evento))) {
        mundo_.manejar(*evento);
    }
    mundo_.step(nroIteracion);
    Cola<std::shared_ptr<Evento>>& eventosOcurridos = mundo_.eventosOcurridos();
    //TODO: get snapshot
    std::shared_ptr<Evento> eventoOcurrido;
    while((obtenido = eventosOcurridos.get(eventoOcurrido))) {
        for (auto& kv : jugadores_) {
            //FIXME: Copiar el evento ocurrido antes de manejarlo, o quitar el move de las colas (se haran copias)
            kv.second->ocurrio(eventoOcurrido);
        }
    }
}

void Partida::correr() {
    asignarVehiculos();
    //TODO: Asignar un auto a cada jugador presente, no poner autos vacios
    double frecuencia = (double)1 / (double)CONFIG_SERVIDOR.simulacionesPorSegundo();
    // Convierto a milisegundos
    // TODO: Uniformizar esto, porque depende de como se usa aca, en el cronometro
    // y en el dormir
    frecuencia *= 1000;
    Cronometro c;
    double t1 = c.ahora();
    uint32_t iteracion = 1;
    while(seguirCorriendo_) {
        step(iteracion);
        double t2 = c.ahora();
        double resto = frecuencia - (t2 - t1);
        if (resto < 0) {
            double atraso = -resto;
            double perdidos = atraso - std::fmod(atraso, frecuencia);
            resto = frecuencia - std::fmod(atraso, frecuencia);
            t1 += perdidos;
            iteracion += std::floor(perdidos / frecuencia);
        }
        dormir(resto);
        t1 += frecuencia;
        iteracion += 1;        
    }
}

void Partida::detener() {
    seguirCorriendo_ = false;
}

void Partida::ocurrio(std::shared_ptr<Evento> unEvento) {
    eventosEntrantes_.put(unEvento);
}

void Partida::asignarVehiculos() {
    for (const auto& kv : jugadores_) {
        uint8_t idVehiculo = mundo_.agregarVehiculo(kv.second->uuid());
        std::shared_ptr<Evento> eventoID = std::make_shared<EventoIDVehiculoDeJugador>(idVehiculo);
        kv.second->ocurrio(eventoID);
    }
}
