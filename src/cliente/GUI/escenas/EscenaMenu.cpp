#include "includes/cliente/GUI/escenas/EscenaMenu.h"

#include "includes/cliente/GUI/AnimacionFactory.h"
#include "includes/cliente/utils/ConfigCliente.h"

EscenaMenu::EscenaMenu(Renderizador& renderizador) :
    sorlo_(AnimacionFactory::instanciar(CONFIG_CLIENTE.sorlo(), renderizador)) {
}

Textura EscenaMenu::dibujate(uint32_t numeroIteracion, Renderizador& renderizador, Area dimensiones) {
    Textura miTextura(renderizador, dimensiones);
    renderizador.setDestino(miTextura);
    /*
    TODO: El dibujaje
    */
    renderizador.dibujar(sorlo_.get(numeroIteracion), miTextura);
    renderizador.resetDestino();
    return std::move(miTextura);
}
