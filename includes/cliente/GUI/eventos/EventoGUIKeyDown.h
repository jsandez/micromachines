#ifndef _EVENTO_GUI_KEY_DOWN_H_
#define _EVENTO_GUI_KEY_DOWN_H_

#include "includes/cliente/GUI/eventos/EventoGUI.h"

class EventoGUIKeyDown : public EventoGUI {
private:
    char caracter_;

public:
    EventoGUIKeyDown(char caracter);
    virtual void actualizar(EventoGUIHandler& handler) override;
};

#endif
