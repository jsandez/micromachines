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
        renderizador_.dibujar(iteracion, escena);
        iteracion+=1;
        SDL_Delay(100);
        // Manejo los eventos despues por si ocurre que se procesan dos clicks (por ejemplo), y se cambia de escena y se procesa el click sin haber dibujado.
        bool obtenido = false;
        std::shared_ptr<EventoGUI> evento;
        while((obtenido = eventosGUI_.get(evento))) {
            escena.manejar(*evento.get());
        }
    }
}

void HiloDibujador::detener() {
    seguirCorriendo_ = false;
}

ColaProtegida<std::shared_ptr<Evento>>& HiloDibujador::eventosEntrantes() {
    return eventos_;
}
