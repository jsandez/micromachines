#include "includes/common/eventos/EventoFactory.h"

#include "includes/common/excepciones/EventoDesconocidoError.h"

std::shared_ptr<Evento> EventoFactory::instanciar(uint32_t uuidRemitente, Protocolo &protocolo) {
  uint16_t UUIDEvento = protocolo.recibirNumUnsigned16();
  switch (UUIDEvento) {

    case UUID_EVENTO_CREAR_PARTIDA:return std::make_shared<EventoCrearPartida>(uuidRemitente, protocolo);

    case UUID_EVENTO_PARTIDA_AGREGADA:return std::make_shared<EventoPartidaAgregada>(uuidRemitente, protocolo);

    case UUID_EVENTO_UNIRSE_A_PARTIDA:return std::make_shared<EventoUnirseAPartida>(uuidRemitente, protocolo);

    case UUID_EVENTO_INICIAR_PARTIDA:return std::make_shared<EventoIniciarPartida>(uuidRemitente, protocolo);

    case UUID_EVENTO_DESCONEXION:return std::make_shared<EventoDesconexion>(uuidRemitente, protocolo);

    case UUID_EVENTO_ACELERAR:return std::make_shared<EventoAcelerar>(uuidRemitente, protocolo);

    case UUID_EVENTO_DESACELERAR:return std::make_shared<EventoDesacelerar>(uuidRemitente, protocolo);

    case UUID_EVENTO_FRENAR:return std::make_shared<EventoFrenar>(uuidRemitente, protocolo);

    case UUID_EVENTO_DEJAR_DE_FRENAR:return std::make_shared<EventoDejarDeFrenar>(uuidRemitente, protocolo);

    case UUID_EVENTO_DOBLAR_IZQUIERDA:return std::make_shared<EventoDoblarIzquierda>(uuidRemitente, protocolo);

    case UUID_EVENTO_DEJAR_DE_DOBLAR_IZQUIERDA:
      return std::make_shared<EventoDejarDeDoblarIzquierda>(uuidRemitente,
                                                            protocolo);

    case UUID_EVENTO_DOBLAR_DERECHA:return std::make_shared<EventoDoblarDerecha>(uuidRemitente, protocolo);

    case UUID_EVENTO_DEJAR_DE_DOBLAR_DERECHA:
      return std::make_shared<EventoDejarDeDoblarDerecha>(uuidRemitente,
                                                          protocolo);

    case UUID_EVENTO_SNAPSHOT:return std::make_shared<EventoSnapshot>(uuidRemitente, protocolo);

    case UUID_EVENTO_PARTIDA_INICIADA:return std::make_shared<EventoPartidaIniciada>(uuidRemitente, protocolo);

    default:throw EventoDesconocidoError(ERROR_EVENTO_DESCONOCIDO);
  }
}
