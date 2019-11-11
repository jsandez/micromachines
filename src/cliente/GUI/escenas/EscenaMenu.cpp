#include "includes/cliente/GUI/escenas/EscenaMenu.h"

#include "includes/cliente/GUI/AnimacionFactory.h"
#include "includes/cliente/utils/ConfigCliente.h"
#include "includes/cliente/GUI/Area.h"

EscenaMenu::EscenaMenu(Renderizador& renderizador, ColaProtegida<std::shared_ptr<EventoGUI>>& eventosGUI) :
    fondoMenu_(AnimacionFactory::instanciar(CONFIG_CLIENTE.uuidFondoMenu(), renderizador)),
    eventosGUI_(eventosGUI) {
}

Textura EscenaMenu::dibujate(uint32_t numeroIteracion, Renderizador& renderizador, Area dimensiones) {
    Textura miTextura(renderizador, dimensiones);
    renderizador.setDestino(miTextura);
    Area areaFondo = Area(0, 0, dimensiones.ancho(), dimensiones.alto());
    renderizador.dibujar(fondoMenu_.get(numeroIteracion), areaFondo);
    renderizador.resetDestino();
    return std::move(miTextura);
}

void EscenaMenu::manejar(EventoGUI& evento) {
    evento.actualizar(*this);
}

#include <iostream>
void EscenaMenu::manejar(EventoGUIClick& evento) {
    std::cout << "Click ñery\n";
}
