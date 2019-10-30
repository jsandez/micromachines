#include "includes/common/eventos/Evento.h"

Evento::Evento(uint32_t uuidRemitente) :
    UUIDRemitente_(uuidRemitente) {
}

uint32_t Evento::uuidRemitente() {
    return UUIDRemitente_;
}
