#include "includes/cliente/GUI/escenas/EscenaSala.h"

#include "includes/cliente/GUI/escenas/EscenaLobby.h"
#include "includes/cliente/GUI/AnimacionFactory.h"
#include "includes/cliente/utils/ConfigCliente.h"
#include "includes/cliente/GUI/Area.h"
#include "includes/cliente/GUI/Texto.h"

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
  // BOTONES VACIOS PARA LAS PARTIDAS
  this->botones.insert(std::pair<int, std::shared_ptr<Boton>>(
      0,
      std::make_shared<Boton>(UUID_BOTON_VACIO,
                              renderizador_,
                              0.45
                                  * CONFIG_CLIENTE.anchoVentana(),
                              0.42
                                  * CONFIG_CLIENTE.altoVentana())));
  this->botones.insert(std::pair<int, std::shared_ptr<Boton>>(
      1,
      std::make_shared<Boton>(UUID_BOTON_VACIO,
                              renderizador_,
                              0.45
                                  * CONFIG_CLIENTE.anchoVentana(),
                              0.52
                                  * CONFIG_CLIENTE.altoVentana())));
  this->botones.insert(std::pair<int, std::shared_ptr<Boton>>(
      2,
      std::make_shared<Boton>(UUID_BOTON_VACIO,
                              renderizador_,
                              0.45
                                  * CONFIG_CLIENTE.anchoVentana(),
                              0.62
                                  * CONFIG_CLIENTE.altoVentana())));
  this->botones.insert(std::pair<int, std::shared_ptr<Boton>>(
      3,
      std::make_shared<Boton>(UUID_BOTON_VACIO,
                              renderizador_,
                              0.45
                                  * CONFIG_CLIENTE.anchoVentana(),
                              0.72
                                  * CONFIG_CLIENTE.altoVentana())));
}

void EscenaSala::inicializarTextoPartidas() {
  // ACA AGARRA LAS PARTIDAS DEL EVENTO SIEMPRE SON 4!!
  textoPartidas.insert(std::pair<int, std::shared_ptr<Texto>>(0,
                                                              std::make_shared<
                                                                  Texto>(
                                                                  "PARTIDA "
                                                                      + std::to_string(
                                                                          partidasId.at(
                                                                              0)),
                                                                  30,
                                                                  renderizador_,
                                                                  UUID_TEXTO_BLANCO)));
  textoPartidas.insert(std::pair<int, std::shared_ptr<Texto>>(1,
                                                              std::make_shared<
                                                                  Texto>(
                                                                  "PARTIDA "
                                                                      + std::to_string(
                                                                          partidasId.at(
                                                                              1)),
                                                                  30,
                                                                  renderizador_,
                                                                  UUID_TEXTO_BLANCO)));
  textoPartidas.insert(std::pair<int, std::shared_ptr<Texto>>(2,
                                                              std::make_shared<
                                                                  Texto>(
                                                                  "PARTIDA "
                                                                      + std::to_string(
                                                                          partidasId.at(
                                                                              2)),
                                                                  30,
                                                                  renderizador_,
                                                                  UUID_TEXTO_BLANCO)));
  textoPartidas.insert(std::pair<int, std::shared_ptr<Texto>>(3,
                                                              std::make_shared<
                                                                  Texto>(
                                                                  "PARTIDA "
                                                                      + std::to_string(
                                                                          partidasId.at(
                                                                              3)),
                                                                  30,
                                                                  renderizador_,
                                                                  UUID_TEXTO_BLANCO)));
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

void EscenaSala::dibujarTextoPartidas(int iteracion) {
  for (const auto &textoPartida: textoPartidas) {
    std::shared_ptr<Boton> botonAsociado = botones.at(textoPartida.first);
    Animacion &animacion = botonAsociado.get()->getAnimacion();
    Area areaTexto = Area(botonAsociado.get()->getX(),
                          botonAsociado.get()->getY(),
                          animacion.ancho(),
                          animacion.alto());
    renderizador_.dibujarTexto(*(textoPartida.second.get()), areaTexto);
  }
}

void EscenaSala::handlerBotones(int uuid) {
  switch (uuid) {
    case UUID_BOTON_CREAR_PARTIDA: {
      std::shared_ptr<Evento>
          eventoCrearPartida = std::make_shared<EventoCrearPartida>();
      eventosAEnviar_.put(eventoCrearPartida);
      // RECIBIR EVENTO PARTIDA CREADA
      std::shared_ptr<Evento>
          eventoUnirseAPartida =
          std::make_shared<EventoUnirseAPartida>(1);
      eventosAEnviar_.put(eventoUnirseAPartida);
      escenas_.emplace(std::make_shared<EscenaLobby>(renderizador_,
                                                     eventosGUI_,
                                                     escenas_,
                                                     eventosAEnviar_,
                                                     this->musicaAmbiente));
      break;
    }
    case UUID_BOTON_UNIRSE_A_PARTIDA: {
      if (partidaSeleccionada != -1) {
        std::shared_ptr<Evento>
            eventoUnirseAPartida =
            std::make_shared<EventoUnirseAPartida>(partidasId.at(
                partidaSeleccionada));
        eventosAEnviar_.put(eventoUnirseAPartida);
        escenas_.emplace(std::make_shared<EscenaLobby>(renderizador_,
                                                       eventosGUI_,
                                                       escenas_,
                                                       eventosAEnviar_,
                                                       this->musicaAmbiente));
      }
      break;
    }
    case 0: {
      if (!partidasId.empty()) {
        partidaSeleccionada = 0;
        for (const auto &texto:textoPartidas){
          texto.second.get()->setColor(UUID_TEXTO_BLANCO);
        }
        textoPartidas.at(0).get()->setColor(UUID_TEXTO_AMARILLO);
        break;
      }
    }
    case 1: {
      if (!partidasId.empty()) {
        partidaSeleccionada = 1;
        for (const auto &texto:textoPartidas){
          texto.second.get()->setColor(UUID_TEXTO_BLANCO);
        }
        textoPartidas.at(1).get()->setColor(UUID_TEXTO_AMARILLO);
        break;
      }
    }
    case 2: {
      if (!partidasId.empty()) {
        partidaSeleccionada = 2;
        for (const auto &texto:textoPartidas){
          texto.second.get()->setColor(UUID_TEXTO_BLANCO);
        }
        textoPartidas.at(2).get()->setColor(UUID_TEXTO_AMARILLO);
        break;
      }
    }
    case 3: {
      if (!partidasId.empty()) {
        partidaSeleccionada = 3;
        for (const auto &texto:textoPartidas){
          texto.second.get()->setColor(UUID_TEXTO_BLANCO);
        }
        textoPartidas.at(3).get()->setColor(UUID_TEXTO_AMARILLO);
        break;
      }
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
    fondoMenu_(AnimacionFactory::instanciar(CONFIG_CLIENTE.uuid("fondoSala"),
                                            renderizador)),
    eventosGUI_(eventosGUI) {
  // TODO: ESCENA SALA RECIBE EL EVENTO SNAPSHOT SALA PARA INICIALIZAR LA LISTA
  // SI ESTA VACIO  EL MAPA ENTONCES LA PARTIDA ES -1
  partidasId.insert(std::pair<int, int>(0, 1));
  partidasId.insert(std::pair<int, int>(1, 23));
  partidasId.insert(std::pair<int, int>(2, 35));
  partidasId.insert(std::pair<int, int>(3, 100));
  partidaSeleccionada = -1;
  inicializarBotones();
  inicializarTextoPartidas();
}

Textura EscenaSala::dibujate(uint32_t numeroIteracion, Area dimensiones) {
  Textura miTextura(renderizador_, dimensiones);
  renderizador_.setDestino(miTextura);
  Area areaFondo = Area(0, 0, dimensiones.ancho(), dimensiones.alto());
  renderizador_.dibujar(fondoMenu_.get(numeroIteracion), areaFondo);
  dibujarBotones(numeroIteracion);
  dibujarTextoPartidas(numeroIteracion);
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
