#include "includes/cliente/GUI/escenas/EscenaMenu.h"

#include "includes/cliente/GUI/AnimacionFactory.h"

EscenaMenu::EscenaMenu() :
    animacion_(AnimacionFactory::sorlo()) {

}

Textura EscenaMenu::dibujate(uint32_t numeroIteracion, Renderizador& renderizador, Area dimensiones) {
    Textura textura(renderizador, dimensiones);
    renderizador.setDestino(textura);
    /*
    TODO: El dibujaje
    */
    renderizador.d();
    renderizador.resetDestino();
    return std::move(textura);
}
