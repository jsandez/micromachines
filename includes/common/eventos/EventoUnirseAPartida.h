#ifndef _EVENTO_UNIRSE_A_PARTIDA_H_
#define _EVENTO_UNIRSE_A_PARTIDA_H_

#include "includes/common/eventos/Evento.h"
#include "includes/common/red/Protocolo.h"

class EventoUnirseAPartida : public Evento {
public:
    EventoUnirseAPartida(uint32_t uuidRemitente, Protocolo& protocolo);
    virtual void enviarse(Protocolo& protocolo) override;
    virtual void actualizar(Handler& handler) override;
};

#endif