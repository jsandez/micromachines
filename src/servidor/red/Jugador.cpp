#include "includes/servidor/red/Jugador.h"

Jugador::Jugador(SocketTCP&& socket, uint32_t uuid, bool& seguirCorriendo) :
    UUID_(uuid),
    socket_(std::move(socket)),
    recibidorEventos_(socket_, eventosRecibidos_, seguirCorriendo),
    enviadorEventos_(socket_, eventosAEnviar_, seguirCorriendo) {
    
    recibidorEventos_.start();
    enviadorEventos_.start();
}

Jugador::~Jugador() {
    eventosRecibidos_.detener();
    eventosAEnviar_.detener();
    socket_.cerrarLectoEscritura();
    recibidorEventos_.join();
    enviadorEventos_.join();
}
