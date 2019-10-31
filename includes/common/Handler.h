#ifndef _HANDLER_H_
#define _HANDLER_H_

#include "includes/common/eventos/Evento.h"
#include "includes/common/eventos/EventoAcelerar.h"
#include "includes/common/eventos/EventoCrearPartida.h"
#include "includes/common/eventos/EventoPartidaAgregada.h"
#include "includes/common/eventos/EventoUnirseAPartida.h"
#include "includes/common/eventos/EventoIniciarPartida.h"
#include "includes/common/eventos/EventoDesconexion.h"

class Handler {
public:
    virtual void manejar(Evento& e) = 0;
    virtual void manejar(EventoAcelerar& e);
    virtual void manejar(EventoCrearPartida& e);
    virtual void manejar(EventoPartidaAgregada& e);
    virtual void manejar(EventoUnirseAPartida& e);
    virtual void manejar(EventoIniciarPartida& e);
    virtual void manejar(EventoDesconexion& e);
};

#endif
