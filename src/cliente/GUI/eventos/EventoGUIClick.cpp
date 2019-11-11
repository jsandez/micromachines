#include "includes/cliente/GUI/eventos/EventoGUIClick.h"

#include "includes/cliente/GUI/EventoGUIHandler.h"

void EventoGUIClick::actualizar(EventoGUIHandler& handler) {
    handler.manejar(*this);
}
