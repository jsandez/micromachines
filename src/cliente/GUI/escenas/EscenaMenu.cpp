#include "includes/cliente/GUI/escenas/EscenaMenu.h"

#include "includes/cliente/GUI/escenas/EscenaSala.h"
#include "includes/cliente/GUI/AnimacionFactory.h"
#include "includes/cliente/utils/ConfigCliente.h"
#include "includes/cliente/GUI/Area.h"

EscenaMenu::EscenaMenu(Renderizador& renderizador, ColaProtegida<std::shared_ptr<EventoGUI>>& eventosGUI, std::stack<std::shared_ptr<Escena>>& escenas) :
    Escena(escenas, renderizador),
    fondoMenu_(AnimacionFactory::instanciar(CONFIG_CLIENTE.uuidFondoMenu(), renderizador)),
    eventosGUI_(eventosGUI) {
}

Textura EscenaMenu::dibujate(uint32_t numeroIteracion, Area dimensiones) {
    Textura miTextura(renderizador_, dimensiones);
    renderizador_.setDestino(miTextura);
    Area areaFondo = Area(0, 0, dimensiones.ancho(), dimensiones.alto());
    renderizador_.dibujar(fondoMenu_.get(numeroIteracion), areaFondo);
    renderizador_.resetDestino();
    return std::move(miTextura);
}

void EscenaMenu::manejar(EventoGUI& evento) {
    evento.actualizar(*this);
}

#include <iostream>

void EscenaMenu::manejar(EventoGUIClick& evento) {
    std::cout << "Click en escena menu\n";
    escenas_.emplace(std::make_shared<EscenaSala>(renderizador_, eventosGUI_, escenas_));
}

void EscenaMenu::manejar(EventoGUIKeyDown& evento) {
    std::cout << "keydown de " << evento.getTecla() << "  en escena menu\n";
}
