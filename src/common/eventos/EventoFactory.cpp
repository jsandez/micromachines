#include "includes/common/eventos/EventoFactory.h"

#include "includes/common/excepciones/EventoDesconocidoError.h"

std::shared_ptr<Evento> EventoFactory::instanciar(uint32_t uuidRemitente, Protocolo& protocolo) {
    uint16_t UUIDEvento = protocolo.recibirNumUnsigned16();
    switch (UUIDEvento) {
    case UUID_EVENTO_CREAR_PARTIDA:
        return std::make_shared<EventoCrearPartida>(uuidRemitente, protocolo);

    case UUID_EVENTO_PARTIDA_AGREGADA:
        return std::make_shared<EventoPartidaAgregada>(uuidRemitente, protocolo);
        
    case UUID_EVENTO_DESCONEXION:
        return std::make_shared<EventoDesconexion>(uuidRemitente, protocolo);

    case UUID_EVENTO_ACELERAR:
        return std::make_shared<EventoAcelerar>(uuidRemitente, protocolo);
    default:
        throw EventoDesconocidoError(ERROR_EVENTO_DESCONOCIDO);
    }
}
