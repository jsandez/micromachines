#include "includes/cliente/GUI/escenas/EscenaSala.h"

#include "includes/cliente/GUI/AnimacionFactory.h"
#include "includes/cliente/utils/ConfigCliente.h"
#include "includes/cliente/GUI/Area.h"

EscenaSala::EscenaSala(Renderizador& renderizador, ColaProtegida<std::shared_ptr<EventoGUI>>& eventosGUI) :
    fondoMenu_(AnimacionFactory::instanciar(CONFIG_CLIENTE.uuidSorlo(), renderizador)),
    eventosGUI_(eventosGUI) {
}

Textura EscenaSala::dibujate(uint32_t numeroIteracion, Renderizador& renderizador, Area dimensiones) {
    Textura miTextura(renderizador, dimensiones);
    renderizador.setDestino(miTextura);
    Area areaFondo = Area(0, 0, dimensiones.ancho(), dimensiones.alto());
    renderizador.dibujar(fondoMenu_.get(numeroIteracion), areaFondo);
    renderizador.resetDestino();
    return std::move(miTextura);
}

void EscenaSala::manejar(EventoGUI& evento) {
    evento.actualizar(*this);
}

#include <iostream>

void EscenaSala::manejar(EventoGUIClick& evento) {
    std::cout << "Click en escena sala\n";
}

void EscenaSala::manejar(EventoGUIKeyDown& evento) {
    std::cout << "keydown en escena sala\n";
}
