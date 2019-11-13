#ifndef _EVENTO_ID_JUGADOR_H_
#define _EVENTO_ID_JUGADOR_H_

#include "includes/common/eventos/Evento.h"
#include "includes/common/red/Protocolo.h"

class EventoIDJugador : public Evento {
public:
    uint32_t uuidJugador_;
    
    EventoIDJugador(uint32_t uuidRemitente, Protocolo& protocolo);
    EventoIDJugador(uint32_t uuidJugador);
    virtual void enviarse(Protocolo& protocolo) override;
    virtual void actualizar(Handler& handler) override;
};

#endif
