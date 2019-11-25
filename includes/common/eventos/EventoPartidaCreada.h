#ifndef _EVENTO_PARTIDA_CREADA_H_
#define _EVENTO_PARTIDA_CREADA_H_

#include "includes/common/eventos/Evento.h"
#include "includes/common/red/Protocolo.h"

class EventoPartidaCreada : public Evento {
public:
    uint16_t uuidPartida_;

    EventoPartidaCreada(uint32_t uuidRemitente, Protocolo& protocolo);
    EventoPartidaCreada(uint16_t uuidPartida);
    virtual void enviarse(Protocolo& protocolo) override;
    virtual void actualizar(Handler& handler) override;
};

#endif
