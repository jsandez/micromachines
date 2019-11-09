#include "includes/cliente/GUI/Escena.h"

Escena::Escena() {
}

Textura Escena::dibujate(uint32_t numeroIteracion, Renderizador& renderizador, Area dimensiones) {
    Textura textura(renderizador, dimensiones);
    return std::move(textura);
}
