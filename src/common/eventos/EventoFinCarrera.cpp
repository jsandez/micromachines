#include "includes/common/eventos/EventoFinCarrera.h"

#include "includes/common/Handler.h"

EventoFinCarrera::EventoFinCarrera() :
    Evento(0) {
    UUIDEvento_ = UUID_EVENTO_FIN_CARRERA;
    //FIXME: implementar con parametrosS
}

EventoFinCarrera::EventoFinCarrera(uint32_t uuidRemitente, Protocolo &protocolo) :
    Evento(uuidRemitente) {
  //FIXME: implementar
}

void EventoFinCarrera::enviarse(Protocolo &protocolo) {
  protocolo.enviar(UUIDEvento_);
  //FIXME: IMPLEMENTAR
}

void EventoFinCarrera::actualizar(Handler &handler) {
  handler.manejar(*this);
}
