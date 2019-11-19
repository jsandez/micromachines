#include <iostream>
#include <includes/cliente/utils/ConfigCliente.h>
#include <includes/cliente/GUI/Texto.h>
#include "includes/cliente/GUI/escenas/EscenaPartida.h"
#include "includes/cliente/GUI/Area.h"

// TODO: Refactorizar
void EscenaPartida::dibujarInterfaz(int iteracion) {
  Texto textoHola("VIDA", 30, renderizador_);
  Area areaHola = Area(5,
                       5,
                       80,
                       20);
  renderizador_.dibujarTexto(textoHola, areaHola);
  Animacion salud(AnimacionFactory::instanciar(200, this->renderizador_));
  std::shared_ptr<ObjetoDinamico> principalCar = pista.obtenerObjeto(id_car);
  Area areaSalud = Area(90, 5, round(principalCar.get()->getVida() * salud.ancho() / 100), salud.alto());
  renderizador_.dibujar(salud.get(iteracion), areaSalud);
}

EscenaPartida::EscenaPartida(Renderizador &renderizador,
                             ColaProtegida<std::shared_ptr<EventoGUI>> &eventosGUI,
                             std::stack<std::shared_ptr<Escena>> &escenas,
                             ColaBloqueante<std::shared_ptr<Evento>> &eventosAEnviar_) : Escena(escenas,
                                                                                                renderizador,
                                                                                                eventosAEnviar_),
                                                                                         eventosGUI_(eventosGUI),
                                                                                         pista("assets/pistas/1.json",
                                                                                               renderizador),
                                                                                         conversor(25.6, 256),
                                                                                         camara(conversor,
                                                                                                pista,
                                                                                                renderizador) {

  // ESTO ES SOLO PARA PROBAR! ESTO DEBERIA SER ALGO SETEADO EN UN EVENTO
  std::shared_ptr<ObjetoDinamico>
      carPrincipal = std::make_shared<ObjetoDinamico>(800, renderizador);

  std::shared_ptr<ObjetoDinamico>
      carSecundario = std::make_shared<ObjetoDinamico>(820, renderizador);

  /*std::shared_ptr<ObjetoDinamico>
      explosion = std::make_shared<ObjetoDinamico>(900, renderizador);

  std::shared_ptr<ObjetoDinamico>
      salud = std::make_shared<ObjetoDinamico>(1000, renderizador);*/

  pista.agregarObjeto(0, carPrincipal);
  pista.agregarObjeto(1, carSecundario);
  //pista.agregarObjeto(2, explosion);
  //pista.agregarObjeto(3, salud);
  camara.setCar(carPrincipal);
  this->id_car = 0;
  /*pista.obtenerObjeto(0).get()->mover(3000, 3000, 0);
  pista.obtenerObjeto(1).get()->mover(3100, 3100, 0);
  pista.obtenerObjeto(2).get()->mover(3200, 3200, 0);
  pista.obtenerObjeto(3).get()->mover(3300, 3300, 0);*/
}

Textura EscenaPartida::dibujate(uint32_t numeroIteracion, Area dimensiones) {
  Textura miTextura(renderizador_, dimensiones);
  renderizador_.setDestino(miTextura);
  this->camara.setWidthHeight(dimensiones.ancho(), dimensiones.alto());
  camara.dibujarPista(numeroIteracion);
  std::shared_ptr<ObjetoDinamico> principalCar = pista.obtenerObjeto(id_car);
  Animacion &animacion = principalCar.get()->getAnimacion();
  Area areaFondo = Area(dimensiones.ancho() / 2 - (float) animacion.ancho() / 2.0f,
                        dimensiones.alto() / 2 - (float) animacion.alto() / 2.0f,
                        animacion.ancho(),
                        animacion.alto());
  renderizador_.dibujar(animacion.get(numeroIteracion), areaFondo, principalCar.get()->getAngulo(), false);
  camara.dibujarObjetos(id_car, numeroIteracion);
  dibujarInterfaz(numeroIteracion);
  renderizador_.resetDestino();
  return std::move(miTextura);
}

void EscenaPartida::manejarInput(EventoGUI &evento) {
  evento.actualizar((EventoGUIHandler &) (*this));
}

void EscenaPartida::manejarInput(EventoGUIClick &evento) {}

void EscenaPartida::manejarInput(EventoGUIKeyDown &evento) {
  if (evento.getTecla() == TECLA_FULLSCREEN) {
    renderizador_.toggleFullScreen();
  } else if (evento.getTecla() == TECLA_ESC) {
    escenas_.pop();
  } else if (evento.getTecla() == TECLA_A) {
    std::shared_ptr<Evento> eventoAcelerar = std::make_shared<EventoAcelerar>();
    eventosAEnviar_.put(eventoAcelerar);
  } else if (evento.getTecla() == TECLA_Z) {
    std::shared_ptr<Evento> eventoFrenar = std::make_shared<EventoFrenar>();
    eventosAEnviar_.put(eventoFrenar);
  } else if (evento.getTecla() == TECLA_IZQ) {
    std::shared_ptr<Evento> eventoDoblarIzq = std::make_shared<EventoDoblarIzquierda>();
    eventosAEnviar_.put(eventoDoblarIzq);
  } else if (evento.getTecla() == TECLA_DER) {
    std::shared_ptr<Evento> eventoDoblarDer = std::make_shared<EventoDoblarDerecha>();
    eventosAEnviar_.put(eventoDoblarDer);
  } else if (evento.getTecla() == TECLA_C) {
    std::shared_ptr<Evento> eventoIniciarPartida = std::make_shared<EventoIniciarPartida>();
    eventosAEnviar_.put(eventoIniciarPartida);
  }
}

void EscenaPartida::manejarInput(EventoGUIKeyUp &evento) {
  if (evento.getTecla() == TECLA_A) {
    std::shared_ptr<Evento> eventoDesacelerar = std::make_shared<EventoDesacelerar>();
    eventosAEnviar_.put(eventoDesacelerar);
  } else if (evento.getTecla() == TECLA_Z) {
    std::shared_ptr<Evento> eventoDejarDeFrenar = std::make_shared<EventoDejarDeFrenar>();
    eventosAEnviar_.put(eventoDejarDeFrenar);
  } else if (evento.getTecla() == TECLA_IZQ) {
    std::shared_ptr<Evento> eventoDejarDeDoblarIzq = std::make_shared<EventoDejarDeDoblarIzquierda>();
    eventosAEnviar_.put(eventoDejarDeDoblarIzq);
  } else if (evento.getTecla() == TECLA_DER) {
    std::shared_ptr<Evento> eventoDejarDeDoblarDer = std::make_shared<EventoDejarDeDoblarDerecha>();
    eventosAEnviar_.put(eventoDejarDeDoblarDer);
  }
}

void EscenaPartida::manejar(Evento &e) {
  e.actualizar((Handler &) (*this));
}

void EscenaPartida::manejar(EventoSnapshot &e) {
  std::map<uint8_t, datosVehiculo_> datos = e.idsADatosVehiculos_;
  for (const auto &kv : datos) {
    float posX = this->conversor.metroAPixel(kv.second.xCoord_);
    // TODO: Fijarse como convertir esto
    float posY = this->conversor.bloqueAPixel(pista.getSizeY()) - this->conversor.metroAPixel(kv.second.yCoord_);
    this->pista.obtenerObjeto(kv.first).get()->mover(posX, posY, kv.second.angulo_);
    this->pista.obtenerObjeto(kv.first).get()->setVida(kv.second.salud_);
  }
}

void EscenaPartida::manejar(EventoIDVehiculoDeJugador &e) {
  uint8_t a = e.idDelVehiculo_;
  this->id_car = a;
  camara.setCar(pista.obtenerObjeto(a));
}

