#include "includes/common/eventos/EventoAparecioConsumible.h"

#include "includes/common/Handler.h"

EventoAparecioConsumible::EventoAparecioConsumible(uint32_t uuidRemitente, Protocolo& protocolo) :
    Evento(uuidRemitente) {
    //TODO: QUE EL PROTOCOLO ENVIE FLOATS
    idConsumible_ = protocolo.recibirNumUnsigned8();
    uint16_t xCoordRed = protocolo.recibirNumUnsigned32();
    xCoord_ = (float)xCoordRed / 100.0f;
    uint16_t yCoordRed = protocolo.recibirNumUnsigned32();
    yCoord_ = (float)yCoordRed / 100.0f;
}

EventoAparecioConsumible::EventoAparecioConsumible(uint8_t idConsumible, float xCoord, float yCoord) :
    Evento(0),
    idConsumible_(idConsumible),
    xCoord_(xCoord),
    yCoord_(yCoord) {
    
    UUIDEvento_ = UUID_EVENTO_APARECIO_CONSUMIBLE;
}

void EventoAparecioConsumible::enviarse(Protocolo& protocolo) {
    protocolo.enviar(UUIDEvento_);
    protocolo.enviar(idConsumible_);
    uint32_t xCoordRed = 100 * xCoord_;
    protocolo.enviar(xCoordRed);
    uint32_t yCoordRed = 100 * yCoord_;
    protocolo.enviar(yCoordRed);
}

void EventoAparecioConsumible::actualizar(Handler& handler) {
    handler.manejar(*this);
}
