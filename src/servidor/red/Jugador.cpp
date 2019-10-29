#include "includes/servidor/red/Jugador.h"

Jugador::Jugador(SocketTCP&& socket) :
    socket_(std::move(socket)) {

}
