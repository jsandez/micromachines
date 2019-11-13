#include "includes/common/eventos/EventoIDJugador.h"

#include "includes/common/Handler.h"

EventoIDJugador::EventoIDJugador(uint32_t uuidRemitente, Protocolo& protocolo) :
    Evento(uuidRemitente) {
        uuidJugador_ = protocolo.recibirNumUnsigned32();
}

EventoIDJugador::EventoIDJugador(uint32_t uuidJugador) :
    Evento(0),
    uuidJugador_(uuidJugador) {        
    UUIDEvento_ = UUID_EVENTO_ID_JUGADOR;
}

void EventoIDJugador::enviarse(Protocolo& protocolo) {
    protocolo.enviar(UUIDEvento_);
    protocolo.enviar(uuidJugador_);
}

void EventoIDJugador::actualizar(Handler& handler) {
    handler.manejar(*this);
}
