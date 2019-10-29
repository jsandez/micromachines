#ifndef _EVENTO_DESCONEXION_H_
#define _EVENTO_DESCONEXION_H_

#include "includes/common/eventos/Evento.h"
#include "includes/common/red/Protocolo.h"

class EventoDesconexion : public Evento {
public:
    EventoDesconexion(Protocolo& protocolo);
    virtual void enviarse(Protocolo& protocolo);
};

#endif
