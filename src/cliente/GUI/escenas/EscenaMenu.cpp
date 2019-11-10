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
    Area areaSorlo = Area(0, 0, sorlo_.ancho(), sorlo_.alto());
    renderizador.dibujar(sorlo_.get(numeroIteracion), areaSorlo);
    renderizador.resetDestino();
    return std::move(miTextura);
}
