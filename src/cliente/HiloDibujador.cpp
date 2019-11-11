#include "includes/cliente/HiloDibujador.h"

#include "includes/cliente/GUI/escenas/EscenaMenu.h"

#include <SDL2/SDL.h>

HiloDibujador::HiloDibujador(Ventana& ventana, Renderizador& renderizador, ColaProtegida<std::shared_ptr<EventoGUI>>& eventosGUI) :
    ventana_(ventana),
    renderizador_(renderizador),
    eventosGUI_(eventosGUI) {
}

void HiloDibujador::correr() {
    EscenaMenu escena(renderizador_, eventosGUI_);    
    uint32_t iteracion = 0;
    while(seguirCorriendo_) {
        bool obtenido = false;
        std::shared_ptr<EventoGUI> evento;
        while((obtenido = eventosGUI_.get(evento))) {
            escena.manejar(*evento.get());
        }
        renderizador_.dibujar(iteracion, escena);
        iteracion+=1;
        SDL_Delay(100);
    }
}

void HiloDibujador::detener() {
    seguirCorriendo_ = false;
}

ColaProtegida<std::shared_ptr<Evento>>& HiloDibujador::eventosEntrantes() {
    return eventos_;
}
