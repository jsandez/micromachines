#include "includes/cliente/GUI/escenas/EscenaMenu.h"
#include "includes/cliente/GUI/escenas/EscenaPartida.h"
#include "includes/cliente/GUI/escenas/EscenaSala.h"
#include "includes/cliente/GUI/AnimacionFactory.h"
#include "includes/cliente/utils/ConfigCliente.h"
#include "includes/cliente/GUI/Area.h"

void EscenaMenu::dibujarBotones(int nroIteracion) {
  for (const auto &boton: botones) {
    Animacion &animacion = boton.second.get()->getAnimacion();
    Area areaBoton = Area(boton.second.get()->getX(),
                          boton.second.get()->getY(),
                          animacion.ancho(),
                          animacion.alto());
    renderizador_.dibujar(animacion.get(nroIteracion), areaBoton);
  }
}

EscenaMenu::EscenaMenu(Renderizador &renderizador,
                       ColaProtegida<std::shared_ptr<EventoGUI>> &eventosGUI,
                       std::stack<std::shared_ptr<Escena>> &escenas,
                       ColaBloqueante<std::shared_ptr<Evento>> &eventosAEnviar_,
                       Sonido &musicaAmbiente) :
    Escena(escenas, renderizador, eventosAEnviar_, musicaAmbiente),
    fondoMenu_(AnimacionFactory::instanciar(CONFIG_CLIENTE.uuid("fondoMenu"),
                                            renderizador)),
    eventosGUI_(eventosGUI) {
  this->botones.insert(std::pair<int, std::shared_ptr<Boton>>(
      UUID_BOTON_CREAR_PARTIDA,
      std::make_shared<Boton>(UUID_BOTON_CREAR_PARTIDA,
                              renderizador,
                              0.41 * CONFIG_CLIENTE.anchoVentana(),
                              0.52 * CONFIG_CLIENTE.altoVentana())));
  this->botones.insert(std::pair<int, std::shared_ptr<Boton>>(
      UUID_BOTON_UNIRSE_A_PARTIDA,
      std::make_shared<Boton>(UUID_BOTON_UNIRSE_A_PARTIDA,
                              renderizador,
                              0.41 * CONFIG_CLIENTE.anchoVentana(),
                              0.62 * CONFIG_CLIENTE.altoVentana())));

  this->botones.insert(std::pair<int, std::shared_ptr<Boton>>(
      UUID_BOTON_SALIR,
      std::make_shared<Boton>(UUID_BOTON_SALIR,
                              renderizador,
                              0.41 * CONFIG_CLIENTE.anchoVentana(),
                              0.72 * CONFIG_CLIENTE.altoVentana())));
  this->musicaAmbiente.setVolume(CONFIG_CLIENTE.volumenAmbiente());
  this->musicaAmbiente.play();
}

Textura EscenaMenu::dibujate(uint32_t numeroIteracion, Area dimensiones) {
  Textura miTextura(renderizador_, dimensiones);
  renderizador_.setDestino(miTextura);
  Area areaFondo = Area(0, 0, dimensiones.ancho(), dimensiones.alto());
  renderizador_.dibujar(fondoMenu_.get(numeroIteracion), areaFondo);
  dibujarBotones(numeroIteracion);
  return std::move(miTextura);
}

void EscenaMenu::manejarInput(EventoGUI &evento) {
  evento.actualizar(*this);
}

#include <iostream>

void EscenaMenu::manejarInput(EventoGUIClick &evento) {
  //FIXME: Segun boton presionado, realizar accion
  int x, y;
  SDL_GetMouseState(&x, &y);
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
