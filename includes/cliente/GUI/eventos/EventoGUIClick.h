#ifndef _EVENTO_GUI_CLICK_H_
#define _EVENTO_GUI_CLICK_H_

#include "includes/cliente/GUI/eventos/EventoGUI.h"

class EventoGUIClick : public EventoGUI {

public:
    virtual void actualizar(EventoGUIHandler& handler) override;
};

#endif
