#include "includes/cliente/GUI/escenas/EscenaMenu.h"
#include "includes/cliente/GUI/escenas/EscenaPartida.h"
#include "includes/cliente/GUI/escenas/EscenaSala.h"
#include "includes/cliente/GUI/AnimacionFactory.h"
#include "includes/cliente/utils/ConfigCliente.h"
#include "includes/cliente/GUI/Area.h"

EscenaMenu::EscenaMenu(Renderizador &renderizador,
                       ColaProtegida<std::shared_ptr<EventoGUI>> &eventosGUI,
                       std::stack<std::shared_ptr<Escena>> &escenas,
                       ColaBloqueante<std::shared_ptr<Evento>> &eventosAEnviar_,
                       Sonido &musicaAmbiente) :
    Escena(escenas, renderizador, eventosAEnviar_, musicaAmbiente),
    fondoMenu_(AnimacionFactory::instanciar(CONFIG_CLIENTE.uuid("fondoMenu"),
                                            renderizador)),
    eventosGUI_(eventosGUI) {
  // TODO: el volume fue hecho setead "ojo", tendria que ser un config tmb?
  this->musicaAmbiente.setVolume(25);
  this->musicaAmbiente.play(true);
}

Textura EscenaMenu::dibujate(uint32_t numeroIteracion, Area dimensiones) {
  Textura miTextura(renderizador_, dimensiones);
  renderizador_.setDestino(miTextura);
  Area areaFondo = Area(0, 0, dimensiones.ancho(), dimensiones.alto());
  renderizador_.dibujar(fondoMenu_.get(numeroIteracion), areaFondo);
  return std::move(miTextura);
}

void EscenaMenu::manejarInput(EventoGUI &evento) {
  evento.actualizar(*this);
}

#include <iostream>

void EscenaMenu::manejarInput(EventoGUIClick &evento) {
  //FIXME: Segun boton presionado, realizar accion
  std::cout << "Click en escena menu: HABRIA QUE PASAR A ESCENA SALA\n";
  std::shared_ptr<Evento>
      eventoCrearPartida = std::make_shared<EventoCrearPartida>();
  eventosAEnviar_.put(eventoCrearPartida);
  std::shared_ptr<Evento>
      eventoUnirseAPartida = std::make_shared<EventoUnirseAPartida>(1);
  eventosAEnviar_.put(eventoUnirseAPartida);

}

void EscenaMenu::manejarInput(EventoGUIKeyDown &evento) {
  if (evento.getTecla() == TECLA_FULLSCREEN) {
    renderizador_.toggleFullScreen();
  }
  if (evento.getTecla() == TECLA_C) {
    std::shared_ptr<Evento> jugar = std::make_shared<EventoIniciarPartida>();
    eventosAEnviar_.put(jugar);
  }
}

void EscenaMenu::manejarInput(EventoGUIKeyUp &evento) {

}

void EscenaMenu::manejar(Evento &e) {
  e.actualizar(*this);
}

void EscenaMenu::manejar(EventoPartidaIniciada &estadoInicial) {
  escenas_.emplace(std::make_shared<EscenaPartida>(renderizador_,
                                                   eventosGUI_,
                                                   escenas_,
                                                   eventosAEnviar_,
                                                   estadoInicial,
                                                   this->musicaAmbiente));
}
