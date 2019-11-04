#include <iostream>
#include "includes/cliente/VentanaPartida.h"
#include "includes/common/Constantes.h"

VentanaPartida::VentanaPartida(SdlWindow &window) :
    window(window),
    pista(1, 15, 15),
    texturasPista(),
    autos(),
    consumibles(),
    conversor(25.6, 256),
    creador_texturas(window) {
  terminado = false;
  deltaCamaraX = 0;
  deltaCamaraY = 0;
  crearPista();
}

void VentanaPartida::crearPista() {
  // ACA DEBERIA ESTAR UN JSON
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
  // TODO: CREAR WRAPPER CAMARA
  int screenX, screenY;
  int xInicial = 0;
  int xFinal = 0;
  int yInicial = 0;
  int yFinal = 0;
  for (std::pair<int, std::shared_ptr<VistaObjeto>> car :autos) {
    if (car.first == 0) {
      window.getWindowSize(&screenX, &screenY);
      // TODO: ACA TENEMOS QUE VERIFICAR CUANDO ES EL AUTO DEL ID; DEBERIA SER EL PRIMERO O ESTAR SEPARADO
      //TODO: SECTOR DE LA CAMARA
      // EL AUTO YA ARRANCA EN EL MEDIO, NO LE SUMO NADA !!!
      deltaCamaraX = car.second.get()->getX();
      deltaCamaraY = car.second.get()->getY();
      if (deltaCamaraX < screenX / 2) {
        // TODO: ESTO DE MOVER ES PARA Q NO TENGA  E Y NEGATIVO; CREO QUE VA DEL LADO DEL SERVER
        car.second.get()->mover((screenX / 2) - deltaCamaraX, 0, 0);
        deltaCamaraX = screenX / 2;
      }
      if (deltaCamaraY < screenY / 2) {
        car.second.get()->mover(0, (screenY / 2) - deltaCamaraY, 0);
        deltaCamaraY = screenY / 2;
      }
      int limiteFinalX = conversor.bloqueAPixel(15) - (screenX / 2);
      int limiteFinalY = conversor.bloqueAPixel(15) - (screenY / 2);
      if (deltaCamaraX > limiteFinalX) {
        // TODO: ESTO DE MOVER ES PARA Q NO TENGA X E Y NEGATIVO; CREO QUE VA DEL LADO DEL SERVER
        car.second.get()->mover(-(deltaCamaraX - limiteFinalX), 0, 0);
        deltaCamaraX = limiteFinalX;
      }
      if (deltaCamaraY > limiteFinalY) {
        car.second.get()->mover(0, -(deltaCamaraY - limiteFinalY), 0);
        deltaCamaraY = limiteFinalY;
      }
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
      car.second.get()->dibujar(screenX / 2,
                                screenY / 2,
                                car.second.get()->getAngulo());
    } else {
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

void VentanaPartida::addAuto(std::shared_ptr<VistaObjeto> car, int id) {
  autos.insert(std::pair<int, std::shared_ptr<VistaObjeto>>(id, car));

}