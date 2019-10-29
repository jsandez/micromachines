#include "includes/servidor/red/Jugador.h"

Jugador::Jugador(SocketTCP&& socket, uint32_t uuid, bool& seguirCorriendo) :
    UUID_(uuid),
    socket_(std::move(socket)),
    recibidorEventos_(socket_, eventosRecibidos_, seguirCorriendo) {
    
    recibidorEventos_.start();
}

Jugador::~Jugador() {
    recibidorEventos_.join();
}
