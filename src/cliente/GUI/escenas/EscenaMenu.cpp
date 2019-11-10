#include "includes/cliente/GUI/escenas/EscenaMenu.h"

#include "includes/cliente/GUI/AnimacionFactory.h"
#include "includes/cliente/utils/ConfigCliente.h"
#include "includes/cliente/GUI/Area.h"

EscenaMenu::EscenaMenu(Renderizador& renderizador) :
    fondoMenu_(AnimacionFactory::instanciar(CONFIG_CLIENTE.uuidFondoMenu(), renderizador)) {
}

Textura EscenaMenu::dibujate(uint32_t numeroIteracion, Renderizador& renderizador, Area dimensiones) {
    Textura miTextura(renderizador, dimensiones);
    renderizador.setDestino(miTextura);
    Area areaSorlo = Area(0, 0, dimensiones.ancho(), dimensiones.alto());
    renderizador.dibujar(fondoMenu_.get(numeroIteracion), areaSorlo);
    renderizador.resetDestino();
    return std::move(miTextura);
}
