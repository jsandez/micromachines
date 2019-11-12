#include <iostream>
#include "includes/cliente/GUI/escenas/EscenaPartida.h"
#include "includes/cliente/GUI/Area.h"

EscenaPartida::EscenaPartida(Renderizador &renderizador,
                             ColaProtegida<std::shared_ptr<EventoGUI>> &eventosGUI,
                             std::stack<std::shared_ptr<Escena>> &escenas) : Escena(escenas, renderizador),
                                                                             eventosGUI_(eventosGUI),
                                                                             pista("assets/pistas/1.json",
                                                                                   renderizador) {}

Textura EscenaPartida::dibujate(uint32_t numeroIteracion, Area dimensiones) {
  Textura miTextura(renderizador_, dimensiones);
  renderizador_.setDestino(miTextura);
  pista.dibujate(numeroIteracion);
  renderizador_.resetDestino();
  return std::move(miTextura);
}

void EscenaPartida::manejar(EventoGUI &evento) {
  evento.actualizar(*this);
}

void EscenaPartida::manejar(EventoGUIClick &evento) {
  std::cout << "LLEGO  EVENTO CLICK" << std::endl;
}

void EscenaPartida::manejar(EventoGUIKeyDown &evento) {
  std::cout << "keydown de " << evento.getTecla() << "  en escena sala\n";
  if (evento.getTecla() == TECLA_ESC) {
    escenas_.pop();
  }
}