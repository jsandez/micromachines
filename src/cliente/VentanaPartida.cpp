#include "includes/cliente/VentanaPartida.h"
#include "includes/common/Constantes.h"

VentanaPartida::VentanaPartida(SdlWindow &window) :
    window(window),
    pista(1, 15, 15),
    texturasPista(),
    objetosDinamicos(),
    conversor(25.6, 256),
    camara(conversor),
    creador_texturas(window) {
  screenX = 0;
  screenY = 0;
  window.getWindowSize(&screenX, &screenY);
  camara.setWidthHeight(screenX, screenY);
  id_car = 0;
  crearPista();
}

void VentanaPartida::crearPista() {
  // DE ESTO SE ENCARGA ELJSON
  texturasPista.insert(std::pair<int, std::shared_ptr<VistaObjeto>>(ID_TIERRA, creador_texturas.crear(ID_TIERRA)));
  texturasPista.insert(std::pair<int, std::shared_ptr<VistaObjeto>>(ID_ASFALTO_RECTO,
                                                                    creador_texturas.crear(ID_ASFALTO_RECTO)));
  for (int j = 0; j < 7; j++) {
    for (int i = 0; i < pista.getSizeX(); i++) {
      pista.agregarBloque(0, j, i, texturasPista.at(ID_TIERRA));
    }
  }

  for (int i = 0; i < pista.getSizeX(); i++) {
    pista.agregarBloque(0, 7, i, texturasPista.at(ID_ASFALTO_RECTO));
  }

  for (int j = 8; j < pista.getSizeY(); j++) {
    for (int i = 0; i < pista.getSizeX(); i++) {
      pista.agregarBloque(0, j, i, texturasPista.at(ID_TIERRA));
    }
  }
}

void VentanaPartida::dibujar() {
  int xInicial = 0;
  int xFinal = 0;
  int yInicial = 0;
  int yFinal = 0;
  std::shared_ptr<VistaObjeto> principalCar = objetosDinamicos[id_car];
  int deltaCamaraX = camara.deltaCamaraX();
  int deltaCamaraY = camara.deltaCamaraY();
  int posCarX = conversor.pixelABloque(deltaCamaraX);
  int posCarY = conversor.pixelABloque(deltaCamaraY);
  xInicial = posCarX - 4;
  xFinal = posCarX + 5;
  yInicial = posCarY - 4;
  yFinal = posCarY + 5;
  if (xInicial < 0) {
    xInicial = 0;
  }
  if (yInicial < 0) {
    yInicial = 0;
  }
  if (xFinal > 15) {
    xFinal = 15;
  }
  if (yFinal > 15) {
    yFinal = 15;
  }
  for (int i = yInicial; i < yFinal; i++) {
    for (int j = xInicial; j < xFinal; j++) {
      pista.getBloque(0, i, j).get()->dibujar(j * 256 - (deltaCamaraX - screenX / 2),
                                              i * 256 - (deltaCamaraY - screenY / 2),
                                              0);
    }
  }
  principalCar.get()->dibujar(screenX / 2,
                              screenY / 2,
                              principalCar.get()->getAngulo());
  for (std::pair<int, std::shared_ptr<VistaObjeto>> car :objetosDinamicos) {
    if (car.first != id_car) {
      int bloqueCarX = conversor.pixelABloque(car.second.get()->getX());
      int bloqueCarY = conversor.pixelABloque(car.second.get()->getY());
      if (bloqueCarX >= xInicial &&
          bloqueCarX <= xFinal &&
          bloqueCarY >= yInicial &&
          bloqueCarY <= yFinal) {
        car.second.get()->dibujar(car.second.get()->getX() - (deltaCamaraX - screenX / 2),
                                  car.second.get()->getY() - (deltaCamaraY - screenY / 2),
                                  car.second.get()->getAngulo());
      }
    }
  }
  window.render();
}

void VentanaPartida::addAutoPrincipal(std::shared_ptr<VistaObjeto> car, int id) {
  id_car = id;
  camara.setCar(car);
  objetosDinamicos.insert(std::pair<int, std::shared_ptr<VistaObjeto>>(id, car));
}

void VentanaPartida::addObjeto(std::shared_ptr<VistaObjeto> object, int id) {
  objetosDinamicos.insert(std::pair<int, std::shared_ptr<VistaObjeto>>(id, object));
}