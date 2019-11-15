#include "includes/common/eventos/EventoIDVehiculoDeJugador.h"

#include "includes/common/Handler.h"

EventoIDVehiculoDeJugador::EventoIDVehiculoDeJugador(uint32_t uuidRemitente, Protocolo& protocolo) :
    Evento(uuidRemitente) {
        idDelVehiculo_ = protocolo.recibirNumUnsigned32();
}

EventoIDVehiculoDeJugador::EventoIDVehiculoDeJugador(uint8_t idDelVehiculo) :
    Evento(0),
    idDelVehiculo_(idDelVehiculo) {        
    UUIDEvento_ = UUID_EVENTO_ID_JUGADOR;
}

void EventoIDVehiculoDeJugador::enviarse(Protocolo& protocolo) {
    protocolo.enviar(UUIDEvento_);
    protocolo.enviar(idDelVehiculo_);
}

void EventoIDVehiculoDeJugador::actualizar(Handler& handler) {
    handler.manejar(*this);
}
