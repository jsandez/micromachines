#ifndef _EVENTO_GUI_HANDLER_H_
#define _EVENTO_GUI_HANDLER_H_

#include "includes/cliente/GUI/eventos/EventoGUI.h"
#include "includes/cliente/GUI/eventos/EventoGUIClick.h"

class EventoGUIHandler {

public:
    virtual void manejar(EventoGUI& evento) = 0;
    virtual void manejar(EventoGUIClick& evento) = 0;
};

#endif
