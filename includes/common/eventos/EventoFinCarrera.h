#ifndef _EVENTO_FIN_CARRERA_H_
#define _EVENTO_FIN_CARRERA_H_

#include "includes/common/eventos/Evento.h"
#include "includes/common/red/Protocolo.h"


class EventoFinCarrera : public Evento {
public:
       
    EventoFinCarrera(uint32_t uuidRemitente, Protocolo& protocolo);
    //FIXME: Constructor local
    //EventoFinCarrera(args);
    EventoFinCarrera();
    virtual void enviarse(Protocolo& protocolo) override;
    virtual void actualizar(Handler& handler) override;
};

#endif
