#include "includes/common/eventos/EventoCrearPartida.h"

EventoCrearPartida::EventoCrearPartida(Protocolo& protocolo) :
    Evento(UUID_EVENTO_CREAR_PARTIDA) {
}

void EventoCrearPartida::enviarse(Protocolo& protocolo) {

}
