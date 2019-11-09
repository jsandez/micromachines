#include "includes/cliente/GUI/Escena.h"

Textura Escena::dibujate(uint32_t numeroIteracion, Renderizador& renderizador, Area dimensiones) {
    Textura textura(renderizador, dimensiones);
    renderizador.setDestino(textura);
    /*
    TODO: El dibujaje
    */
    renderizador.d();
    renderizador.resetDestino();
    return std::move(textura);
}
