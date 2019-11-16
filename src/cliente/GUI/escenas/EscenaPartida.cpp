#include <iostream>
#include "includes/cliente/GUI/escenas/EscenaPartida.h"
#include "includes/cliente/GUI/Area.h"

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

  std::shared_ptr<ObjetoDinamico>
      explosion = std::make_shared<ObjetoDinamico>(900, renderizador);

  std::shared_ptr<ObjetoDinamico>
      salud = std::make_shared<ObjetoDinamico>(1000, renderizador);

  pista.agregarObjeto(0, carPrincipal);
  pista.agregarObjeto(1, carSecundario);
  pista.agregarObjeto(2, explosion);
  pista.agregarObjeto(3, salud);
  camara.setCar(carPrincipal);
  this->id_car = 0;
  pista.obtenerObjeto(0).get()->mover(3000, 3000, -90);
  pista.obtenerObjeto(1).get()->mover(3100, 3100, -90);
  pista.obtenerObjeto(2).get()->mover(3200, 3200, -90);
  pista.obtenerObjeto(3).get()->mover(3300, 3300, 0);
}

Textura EscenaPartida::dibujate(uint32_t numeroIteracion, Area dimensiones) {
  Textura miTextura(renderizador_, dimensiones);
  renderizador_.setDestino(miTextura);
  this->camara.setWidthHeight(dimensiones.ancho(), dimensiones.alto());
  camara.dibujarPista(numeroIteracion);
  std::shared_ptr<ObjetoDinamico> principalCar = pista.obtenerObjeto(id_car);
  Animacion &animacion = principalCar.get()->getAnimacion();
  Area areaFondo = Area(dimensiones.ancho() / 2,
                        dimensiones.alto() / 2,
                        animacion.ancho(),
                        animacion.alto());
  renderizador_.dibujar(animacion.get(numeroIteracion), areaFondo, principalCar.get()->getAngulo(), false);
  camara.dibujarObjetos(id_car, numeroIteracion);
  renderizador_.resetDestino();
  return std::move(miTextura);
}

void EscenaPartida::manejarInput(EventoGUI &evento) {
  evento.actualizar((EventoGUIHandler &) (*this));
}

void EscenaPartida::manejarInput(EventoGUIClick &evento) {
  // TODO: ESTO ES UNA PRUEBA PARA VER QUE SE MUEVA EL AUTO Y NADA MAS!!
  /*
  ObjetoDinamico *carPrincipal = this->pista.obtenerObjeto(id_car).get();
  carPrincipal->mover(carPrincipal->getX() + 5, carPrincipal->getY() + 5, carPrincipal->getAngulo());*/
  std::shared_ptr<Evento> eventoAcelerar = std::make_shared<EventoAcelerar>();

}

void EscenaPartida::manejarInput(EventoGUIKeyDown &evento) {
  if (evento.getTecla() == TECLA_FULLSCREEN) {
    renderizador_.toggleFullScreen();
  } else if (evento.getTecla() == TECLA_ESC) {
    escenas_.pop();
  }
}

void EscenaPartida::manejar(Evento &e) {
  e.actualizar((Handler &) (*this));
}

void EscenaPartida::manejar(EventoSnapshot &e) {
  std::map<uint8_t, datosVehiculo_> datos = e.idsADatosVehiculos_;
  for (const auto &kv : datos) {
    this->pista.obtenerObjeto(0).get()->mover(kv.second.xCoord_, kv.second.yCoord_, kv.second.angulo_);
    this->pista.obtenerObjeto(0).get()->setVida(kv.second.salud_);
  }
}

void EscenaPartida::manejar(EventoIDVehiculoDeJugador &e) {
  
}
