#include "includes/servidor/red/Jugador.h"

Jugador::Jugador(SocketTCP&& socket, uint32_t uuid, bool& seguirCorriendo, ColaBloqueante<std::shared_ptr<Evento>>& destinoEventos) :
    UUID_(uuid),
    socket_(std::move(socket)),
    destino_(destinoEventos),
    recibidorEventos_(socket_, destino_, seguirCorriendo, UUID_),
    enviadorEventos_(socket_, eventosAEnviar_, seguirCorriendo) {
    
    recibidorEventos_.start();
    enviadorEventos_.start();
}

Jugador::~Jugador() {
    eventosAEnviar_.detener();
    socket_.cerrarLectoEscritura();
    recibidorEventos_.join();
    enviadorEventos_.join();
}

uint32_t Jugador::uuid () {
    return UUID_;
}
