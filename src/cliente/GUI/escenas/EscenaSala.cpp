#include "includes/cliente/GUI/escenas/EscenaSala.h"

#include "includes/cliente/GUI/AnimacionFactory.h"
#include "includes/cliente/utils/ConfigCliente.h"
#include "includes/cliente/GUI/Area.h"

EscenaSala::EscenaSala(Renderizador &renderizador,
                       ColaProtegida<std::shared_ptr<EventoGUI>> &eventosGUI,
                       std::stack<std::shared_ptr<Escena>> &escenas) :
    Escena(escenas, renderizador),
    fondoMenu_(AnimacionFactory::instanciar(CONFIG_CLIENTE.uuid("sorlo"), renderizador)),
    eventosGUI_(eventosGUI) {
}

Textura EscenaSala::dibujate(uint32_t numeroIteracion, Area dimensiones) {
  Textura miTextura(renderizador_, dimensiones);
  renderizador_.setDestino(miTextura);
  Area areaFondo = Area(0, 0, dimensiones.ancho(), dimensiones.alto());
  renderizador_.dibujar(fondoMenu_.get(numeroIteracion), areaFondo);
  renderizador_.resetDestino();
  return std::move(miTextura);
}

void EscenaSala::manejarInput(EventoGUI &evento) {
  evento.actualizar(*this);
}

#include <iostream>

void EscenaSala::manejarInput(EventoGUIClick &evento) {
  std::cout << "Click en escena sala\n";
}

void EscenaSala::manejarInput(EventoGUIKeyDown &evento) {
  std::cout << "keydown de " << evento.getTecla() << "  en escena sala\n";
  if (evento.getTecla() == TECLA_ESC) {
    escenas_.pop();
  }
}

void EscenaSala::manejar(Evento &e) {}
