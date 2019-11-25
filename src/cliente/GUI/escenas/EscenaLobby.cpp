#include "includes/cliente/GUI/escenas/EscenaLobby.h"

#include "includes/cliente/GUI/AnimacionFactory.h"
#include "includes/cliente/utils/ConfigCliente.h"
#include "includes/cliente/GUI/Area.h"

void EscenaLobby::inicializarBotones() {
  this->botones.insert(std::pair<int, std::shared_ptr<Boton>>(
      UUID_BOTON_INICIAR_PARTIDA,
      std::make_shared<Boton>(UUID_BOTON_INICIAR_PARTIDA,
                              renderizador_,
                              0.10
                                  * CONFIG_CLIENTE.anchoVentana(),
                              0.60
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

void EscenaLobby::inicializarTextoJugadores() {
  textoJugadores.insert(std::pair<int, std::shared_ptr<Texto>>(0,
                                                               std::make_shared<
                                                                   Texto>(
                                                                   "JUGADOR "
                                                                       + std::to_string(
                                                                           jugadoresId.at(
                                                                               0)),
                                                                   30,
                                                                   renderizador_,
                                                                   UUID_TEXTO_BLANCO)));
  textoJugadores.insert(std::pair<int, std::shared_ptr<Texto>>(1,
                                                               std::make_shared<
                                                                   Texto>(
                                                                   "JUGADOR "
                                                                       + std::to_string(
                                                                           jugadoresId.at(
                                                                               1)),
                                                                   30,
                                                                   renderizador_,
                                                                   UUID_TEXTO_BLANCO)));
  textoJugadores.insert(std::pair<int, std::shared_ptr<Texto>>(2,
                                                               std::make_shared<
                                                                   Texto>(
                                                                   "JUGADOR "
                                                                       + std::to_string(
                                                                           jugadoresId.at(
                                                                               2)),
                                                                   30,
                                                                   renderizador_,
                                                                   UUID_TEXTO_BLANCO)));
  textoJugadores.insert(std::pair<int, std::shared_ptr<Texto>>(3,
                                                               std::make_shared<
                                                                   Texto>(
                                                                   "JUGADOR "
                                                                       + std::to_string(
                                                                           jugadoresId.at(
                                                                               3)),
                                                                   30,
                                                                   renderizador_,
                                                                   UUID_TEXTO_BLANCO)));
}

void EscenaLobby::dibujarBotones(int nroIteracion) {
  for (const auto &boton: botones) {
    Animacion &animacion = boton.second.get()->getAnimacion();
    Area areaBoton = Area(boton.second.get()->getX(),
                          boton.second.get()->getY(),
                          animacion.ancho(),
                          animacion.alto());
    renderizador_.dibujar(animacion.get(nroIteracion), areaBoton);
  }
}

void EscenaLobby::handlerBotones(int uuid) {
  switch (uuid) {
    case UUID_BOTON_INICIAR_PARTIDA: {
      std::shared_ptr<Evento> jugar = std::make_shared<EventoIniciarPartida>();
      eventosAEnviar_.put(jugar);
      break;
    }
    case UUID_BOTON_ATRAS: {
      escenas_.pop();
    }
    default:break;
  }
}

void EscenaLobby::dibujarTextoJugadores(int iteracion) {
  double i = 0;
  for (const auto &textoJugador: textoJugadores) {
    Area areaTexto = Area(0.45 * CONFIG_CLIENTE.anchoVentana(),
                          (0.42 + i) * CONFIG_CLIENTE.altoVentana(),
                          247,
                          31);
    renderizador_.dibujarTexto(*(textoJugador.second.get()), areaTexto);
    i = i +0.10;
  }
}

EscenaLobby::EscenaLobby(Renderizador &renderizador,
                         ColaProtegida<std::shared_ptr<EventoGUI>> &eventosGUI,
                         std::stack<std::shared_ptr<Escena>> &escenas,
                         ColaBloqueante<std::shared_ptr<Evento>> &eventosAEnviar_,
                         Sonido &musicaAmbiente) :
    Escena(escenas, renderizador, eventosAEnviar_, musicaAmbiente),
    fondoMenu_(AnimacionFactory::instanciar(CONFIG_CLIENTE.uuid("fondoSala"),
                                            renderizador)),
    eventosGUI_(eventosGUI) {
  jugadoresId.insert(std::pair<int, int>(0, 1));
  jugadoresId.insert(std::pair<int, int>(1, 2));
  jugadoresId.insert(std::pair<int, int>(2, 3));
  jugadoresId.insert(std::pair<int, int>(3, 4));
  inicializarBotones();
  inicializarTextoJugadores();
}

Textura EscenaLobby::dibujate(uint32_t numeroIteracion, Area dimensiones) {
  Textura miTextura(renderizador_, dimensiones);
  renderizador_.setDestino(miTextura);
  Area areaFondo = Area(0, 0, dimensiones.ancho(), dimensiones.alto());
  renderizador_.dibujar(fondoMenu_.get(numeroIteracion), areaFondo);
  dibujarBotones(numeroIteracion);
  dibujarTextoJugadores(numeroIteracion);
  return std::move(miTextura);
}

void EscenaLobby::manejarInput(EventoGUI &evento) {
  evento.actualizar(*this);
}

#include <iostream>
#include <includes/cliente/GUI/escenas/EscenaPartida.h>

void EscenaLobby::manejarInput(EventoGUIClick &evento) {
  int x, y;
  SDL_GetMouseState(&x, &y);
  for (const auto &boton: botones) {
    if (boton.second.get()->estaSeleccionado(x, y)) {
      handlerBotones(boton.first);
      break;
    }
  }
}

void EscenaLobby::manejarInput(EventoGUIKeyDown &evento) {
  if (evento.getTecla() == TECLA_ESC) {
    escenas_.pop();
  }
  if (evento.getTecla() == TECLA_FULLSCREEN) {
    renderizador_.toggleFullScreen();
  }
}

void EscenaLobby::manejarInput(EventoGUIKeyUp &evento) {}

void EscenaLobby::manejar(Evento &e) {
  e.actualizar(*this);
}

void EscenaLobby::manejar(EventoPartidaIniciada &estadoInicial) {
  escenas_.emplace(std::make_shared<EscenaPartida>(renderizador_,
                                                   eventosGUI_,
                                                   escenas_,
                                                   eventosAEnviar_,
                                                   estadoInicial,
                                                   this->musicaAmbiente));
}
