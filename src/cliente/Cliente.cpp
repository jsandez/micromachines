#include "includes/cliente/Cliente.h"

#include <memory>


#include "includes/cliente/utils/ConfigCliente.h"
#include "includes/cliente/GUI/Ventana.h"
#include "includes/cliente/GUI/Escena.h"

#include <SDL2/SDL.h>

Cliente::Cliente() {
}

void Cliente::correr() {
    std::shared_ptr<Ventana> ventana = std::make_shared<Ventana>(CONFIG_CLIENTE.anchoVentana(),
        CONFIG_CLIENTE.altoVentana(),
        CONFIG_CLIENTE.pantallaCompleta(),
        CONFIG_CLIENTE.tituloVentana());

    Renderizador r(ventana);
    Escena e;
    r.dibujar(1, e);
    SDL_Delay(3000);
}

void Cliente::cerrar() {

}
