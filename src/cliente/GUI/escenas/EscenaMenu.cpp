#include "includes/cliente/GUI/escenas/EscenaMenu.h"
#include "includes/cliente/GUI/escenas/EscenaPartida.h"
#include "includes/cliente/GUI/escenas/EscenaSala.h"
#include "includes/cliente/GUI/AnimacionFactory.h"
#include "includes/cliente/utils/ConfigCliente.h"
#include "includes/cliente/GUI/Area.h"

EscenaMenu::EscenaMenu(Renderizador &renderizador,
                       ColaProtegida<std::shared_ptr<EventoGUI>> &eventosGUI,
                       std::stack<std::shared_ptr<Escena>> &escenas,
                       ColaBloqueante<std::shared_ptr<Evento>> &eventosAEnviar_) :
    Escena(escenas, renderizador, eventosAEnviar_),
    fondoMenu_(AnimacionFactory::instanciar(CONFIG_CLIENTE.uuid("fondoMenu"), renderizador)),
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

void EscenaMenu::manejarInput(EventoGUI &evento) {
  evento.actualizar(*this);
}

#include <iostream>

void EscenaMenu::manejarInput(EventoGUIClick &evento) {
  std::cout << "Click en escena menu\n";
  //escenas_.emplace(std::make_shared<EscenaSala>(renderizador_, eventosGUI_, escenas_));
  std::shared_ptr<Evento> eventoCrearPartida = std::make_shared<EventoCrearPartida>();
  eventosAEnviar_.put(eventoCrearPartida);
  std::shared_ptr<Evento> eventoUnirseAPartida = std::make_shared<EventoUnirseAPartida>(1);
  eventosAEnviar_.put(eventoUnirseAPartida);
  escenas_.emplace(std::make_shared<EscenaPartida>(renderizador_, eventosGUI_, escenas_, eventosAEnviar_));
}

void EscenaMenu::manejarInput(EventoGUIKeyDown &evento) {
  if (evento.getTecla() == TECLA_FULLSCREEN) {
    renderizador_.toggleFullScreen();
  }
}

void EscenaMenu::manejarInput(EventoGUIKeyUp &evento) {}

void EscenaMenu::manejar(Evento &e) {}
