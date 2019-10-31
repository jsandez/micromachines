#include "includes/common/eventos/EventoUnirseAPartida.h"

#include "includes/common/Handler.h"

EventoUnirseAPartida::EventoUnirseAPartida(uint32_t uuidRemitente, Protocolo& protocolo) :
    Evento(uuidRemitente) {
        uuidPartida_ = protocolo.recibirNumUnsigned16();
}

EventoUnirseAPartida::EventoUnirseAPartida(uint32_t uuidRemitente, uint16_t uuidPartida) :
    Evento(uuidRemitente),
    uuidPartida_(uuidPartida) {
}

void EventoUnirseAPartida::enviarse(Protocolo& protocolo) {

}

void EventoUnirseAPartida::actualizar(Handler& handler) {
    handler.manejar(*this);
}
