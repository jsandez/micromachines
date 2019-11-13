#include "includes/cliente/HiloDibujador.h"

#include "includes/cliente/GUI/escenas/EscenaMenu.h"

#include <SDL2/SDL.h>

HiloDibujador::HiloDibujador(Ventana& ventana, Renderizador& renderizador, ColaProtegida<std::shared_ptr<EventoGUI>>& eventosGUI) :
    ventana_(ventana),
    renderizador_(renderizador),
    eventosGUI_(eventosGUI) {
    
    escenas_.emplace(std::make_shared<EscenaMenu>(renderizador_, eventosGUI_, escenas_));
}

void HiloDibujador::correr() {
    //TODO: Resetear cada vez que se cambia de escena
    uint32_t iteracion = 0;
    while(seguirCorriendo_) {
        Escena& escenaActual = *escenas_.top().get();
        renderizador_.dibujar(iteracion, escenaActual);
        iteracion += 1;
        SDL_Delay(100);
        //FIXME: Se arregla haciendo que el metodo manejar evento devuelva true si hay que continuar.
        // También se puede chequear al hacer pop que no se esté quedando sin escenas
        bool obtenido = false;
        std::shared_ptr<EventoGUI> evento;
        while((obtenido = eventosGUI_.get(evento))) {
            escenaActual.manejar(*evento.get());
        }
    }
}

void HiloDibujador::detener() {
    seguirCorriendo_ = false;
}

ColaProtegida<std::shared_ptr<Evento>>& HiloDibujador::eventosEntrantes() {
    return eventos_;
}
