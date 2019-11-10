#include "includes/cliente/GUI/escenas/EscenaMenu.h"

#include "includes/cliente/GUI/AnimacionFactory.h"
#include "includes/cliente/utils/ConfigCliente.h"
#include "includes/cliente/GUI/Area.h"

EscenaMenu::EscenaMenu(Renderizador& renderizador) :
    sorlo_(AnimacionFactory::instanciar(CONFIG_CLIENTE.uuidSorlo(), renderizador)) {
}

Textura EscenaMenu::dibujate(uint32_t numeroIteracion, Renderizador& renderizador, Area dimensiones) {
    Textura miTextura(renderizador, dimensiones);
    renderizador.setDestino(miTextura);
    Area destinoSorlo = Area(0, 0, 71, 71);
    renderizador.dibujar(sorlo_.get(numeroIteracion), destinoSorlo);
    renderizador.resetDestino();
    return std::move(miTextura);
}
