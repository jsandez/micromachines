#include "includes/cliente/GUI/eventos/EventoGUIKeyDown.h"

#include "includes/cliente/GUI/EventoGUIHandler.h"

EventoGUIKeyDown::EventoGUIKeyDown(char caracter)
    : caracter_(caracter) {
}

void EventoGUIKeyDown::actualizar(EventoGUIHandler& handler) {
    handler.manejar(*this);
}
