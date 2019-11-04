#include <iostream>
#include "includes/cliente/VentanaPartida.h"

VentanaPartida::VentanaPartida(SdlWindow &window) :
    window(window),
    pista(),
    texturasPista(),
    autos(),
    consumibles(),
    conversor(25.6, 256),
    creador_texturas(window) {
  terminado = false;
  deltaCamaraX = 0;
  deltaCamaraY = 0;
}

void VentanaPartida::crearPista() {
  // TODO: TIENE QUE HABER UN WRAPPER PARA PISTA?
  // TODO: QUEDA MUY FEO ESTA ESTRUCTURA
  texturasPista.insert(std::pair<int, std::shared_ptr<VistaObjeto>>(100, creador_texturas.crear(100)));
  texturasPista.insert(std::pair<int, std::shared_ptr<VistaObjeto>>(102, creador_texturas.crear(102)));
  std::vector<std::vector<std::shared_ptr<VistaObjeto>>> matrix;
  std::vector<std::shared_ptr<VistaObjeto>> arrayTierra;
  std::vector<std::shared_ptr<VistaObjeto>> arrayAsfalto;
  for (int j = 0; j < 30; j++) {
    arrayTierra.push_back(texturasPista.at(100));
  }
  matrix.push_back(arrayTierra);
  matrix.push_back(arrayTierra);
  matrix.push_back(arrayTierra);
  matrix.push_back(arrayTierra);
  matrix.push_back(arrayTierra);
  matrix.push_back(arrayTierra);
  matrix.push_back(arrayTierra);
  for (int j = 0; j < 30; j++) {
    arrayAsfalto.push_back(texturasPista.at(102));
  }
  matrix.push_back(arrayAsfalto);
  matrix.push_back(arrayTierra);
  matrix.push_back(arrayTierra);
  matrix.push_back(arrayTierra);
  matrix.push_back(arrayTierra);
  matrix.push_back(arrayTierra);
  matrix.push_back(arrayTierra);
  matrix.push_back(arrayTierra);
  pista.insert(std::pair<int, std::vector<std::vector<std::shared_ptr<VistaObjeto>>>>(0, matrix));
}

void VentanaPartida::dibujar() {
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
      int limiteFinalX = conversor.bloqueAPixel(30) - (screenX / 2);
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
      xInicial = posCarX - 3;
      xFinal = posCarX + 4;
      yInicial = posCarY - 3;
      yFinal = posCarY + 4;
      if (xInicial < 0) {
        xInicial = 0;
      }
      if (yInicial < 0) {
        yInicial = 0;
      }
      if (xFinal > 30) {
        xFinal = 30;
      }
      if (yFinal > 15) {
        yFinal = 15;
      }
      std::cout << "posCarX: " << posCarX << std::endl;
      std::cout << "posCarY: " << posCarY << std::endl;
      std::cout << "xInicial: " << xInicial << std::endl;
      std::cout << "yInicial: " << yInicial << std::endl;
      std::cout << "xFinal: " << xFinal << std::endl;
      std::cout << "yFinsal: " << yFinal << std::endl;
      std::vector<std::vector<std::shared_ptr<VistaObjeto>>> matrix = pista.at(0);
      for (int i = yInicial; i < yFinal; i++) {
        for (int j = xInicial; j < xFinal; j++) {
          matrix[i][j].get()->dibujar(j * 256 - (deltaCamaraX - screenX / 2),
                                      i * 256 - (deltaCamaraY - screenY / 2),
                                      0);
        }
      }
      car.second.get()->dibujar(screenX / 2,
                                screenY / 2,
                                car.second.get()->getAngulo());
    } else {
      // VERIFICO QUE CAIGA EN LOS BLOQUES
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