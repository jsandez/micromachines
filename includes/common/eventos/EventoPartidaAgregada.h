#ifndef _EVENTO_PARTIDA_AGREGADA_H_
#define _EVENTO_PARTIDA_AGREGADA_H_

#include "includes/common/eventos/Evento.h"
#include "includes/common/red/Protocolo.h"

class EventoPartidaAgregada : public Evento {
public:
    uint16_t cantidadPartidas_;
    
    EventoPartidaAgregada(uint32_t uuidRemitente, Protocolo& protocolo);
    EventoPartidaAgregada(uint32_t uuidRemitente, uint16_t cantidadPartidas);
    virtual void enviarse(Protocolo& protocolo) override;
    virtual void actualizar(Handler& handler) override;
    
};

#endif
