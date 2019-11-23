#include "includes/cliente/GUI/escenas/EscenaSala.h"

#include "includes/cliente/GUI/escenas/EscenaLobby.h"
#include "includes/cliente/GUI/AnimacionFactory.h"
#include "includes/cliente/utils/ConfigCliente.h"
#include "includes/cliente/GUI/Area.h"

void EscenaSala::inicializarBotones() {
  this->botones.insert(std::pair<int, std::shared_ptr<Boton>>(
      UUID_BOTON_CREAR_PARTIDA,
      std::make_shared<Boton>(UUID_BOTON_CREAR_PARTIDA,
                              renderizador_,
                              0.10
                                  * CONFIG_CLIENTE.anchoVentana(),
                              0.60
                                  * CONFIG_CLIENTE.altoVentana())));
  this->botones.insert(std::pair<int, std::shared_ptr<Boton>>(
      UUID_BOTON_UNIRSE_A_PARTIDA,
      std::make_shared<Boton>(UUID_BOTON_UNIRSE_A_PARTIDA,
                              renderizador_,
                              0.10
                                  * CONFIG_CLIENTE.anchoVentana(),
                              0.65
                                  * CONFIG_CLIENTE.altoVentana())));

  this->botones.insert(std::pair<int, std::shared_ptr<Boton>>(
      UUID_BOTON_ATRAS,
      std::make_shared<Boton>(UUID_BOTON_ATRAS,
                              renderizador_,
                              0.10
                                  * CONFIG_CLIENTE.anchoVentana(),
                              0.70
                                  * CONFIG_CLIENTE.altoVentana())));
}

void EscenaSala::dibujarBotones(int nroIteracion) {
  for (const auto &boton: botones) {
    Animacion &animacion = boton.second.get()->getAnimacion();
    Area areaBoton = Area(boton.second.get()->getX(),
                          boton.second.get()->getY(),
                          animacion.ancho(),
                          animacion.alto());
    renderizador_.dibujar(animacion.get(nroIteracion), areaBoton);
  }
}

void EscenaSala::handlerBotones(int uuid) {
  switch (uuid) {
    case UUID_BOTON_CREAR_PARTIDA: {
      std::shared_ptr<Evento>
          eventoCrearPartida = std::make_shared<EventoCrearPartida>();
      eventosAEnviar_.put(eventoCrearPartida);
      break;
    }
    case UUID_BOTON_UNIRSE_A_PARTIDA: {
      std::shared_ptr<Evento>
          eventoUnirseAPartida = std::make_shared<EventoUnirseAPartida>(1);
      eventosAEnviar_.put(eventoUnirseAPartida);
      escenas_.emplace(std::make_shared<EscenaLobby>(renderizador_,
                                                     eventosGUI_,
                                                     escenas_,
                                                     eventosAEnviar_,
                                                     this->musicaAmbiente));
      break;
    }
    case UUID_BOTON_ATRAS: {
      escenas_.pop();
    }
    default:break;
  }
}

EscenaSala::EscenaSala(Renderizador &renderizador,
                       ColaProtegida<std::shared_ptr<EventoGUI>> &eventosGUI,
                       std::stack<std::shared_ptr<Escena>> &escenas,
                       ColaBloqueante<std::shared_ptr<Evento>> &eventosAEnviar_,
                       Sonido &musicaAmbiente) :
    Escena(escenas, renderizador, eventosAEnviar_, musicaAmbiente),
    fondoMenu_(AnimacionFactory::instanciar(CONFIG_CLIENTE.uuid("fondoMenu"),
                                            renderizador)),
    eventosGUI_(eventosGUI) {
  inicializarBotones();
}

Textura EscenaSala::dibujate(uint32_t numeroIteracion, Area dimensiones) {
  Textura miTextura(renderizador_, dimensiones);
  renderizador_.setDestino(miTextura);
  Area areaFondo = Area(0, 0, dimensiones.ancho(), dimensiones.alto());
  renderizador_.dibujar(fondoMenu_.get(numeroIteracion), areaFondo);
  dibujarBotones(numeroIteracion);
  return std::move(miTextura);
}

void EscenaSala::manejarInput(EventoGUI &evento) {
  evento.actualizar(*this);
}

#include <iostream>
#include <includes/cliente/GUI/escenas/EscenaPartida.h>
#include <includes/cliente/GUI/escenas/EscenaLobby.h>

void EscenaSala::manejarInput(EventoGUIClick &evento) {
  int x, y;
  SDL_GetMouseState(&x, &y);
  for (const auto &boton: botones) {
    if (boton.second.get()->estaSeleccionado(x, y)) {
      handlerBotones(boton.first);
      break;
    }
  }
}

void EscenaSala::manejarInput(EventoGUIKeyDown &evento) {
  if (evento.getTecla() == TECLA_ESC) {
    escenas_.pop();
  }
  if (evento.getTecla() == TECLA_FULLSCREEN) {
    renderizador_.toggleFullScreen();
  }
}

void EscenaSala::manejarInput(EventoGUIKeyUp &evento) {}

void EscenaSala::manejar(Evento &e) {
  e.actualizar(*this);
}
