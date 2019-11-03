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
  for (int j = 0; j < 20; j++) {
    arrayTierra.push_back(texturasPista.at(100));
  }
  matrix.push_back(arrayTierra);
  matrix.push_back(arrayTierra);
  matrix.push_back(arrayTierra);
  for (int j = 0; j < 20; j++) {
    arrayAsfalto.push_back(texturasPista.at(102));
  }
  matrix.push_back(arrayAsfalto);
  matrix.push_back(arrayTierra);
  matrix.push_back(arrayTierra);
  matrix.push_back(arrayTierra);
  pista.insert(std::pair<int, std::vector<std::vector<std::shared_ptr<VistaObjeto>>>>(0, matrix));
}

void VentanaPartida::dibujar() {
  int screenX, screenY;
  for (std::pair<int, std::shared_ptr<VistaObjeto>> car :autos) {
    window.getWindowSize(&screenX, &screenY);
    // TODO: ACA TENEMOS QUE VERIFICAR CUANDO ES EL AUTO DEL ID; DEBERIA SER EL PRIMERO O ESTAR SEPARADO
    //TODO: SECTOR DE LA CAMARA
    deltaCamaraX = car.second.get()->getX();
    deltaCamaraY = car.second.get()->getY();
    if (deltaCamaraX < 0) {
      car.second.get()->mover(-deltaCamaraX,0,0);
      deltaCamaraX = 0;
    }
    if (deltaCamaraY < 0) {
      car.second.get()->mover(0,-deltaCamaraY,0);
      deltaCamaraY = 0;
    }
    int posCarX = conversor.pixelABloque(deltaCamaraX + screenX / 2);
    int posCarY = conversor.pixelABloque(deltaCamaraY + screenY / 2);
    int xInicial = posCarX - 3;
    int xFinal = posCarX + 3;
    int yInicial = posCarY - 3;
    int yFinal = posCarY + 3;
    if (xInicial < 0) {
      xInicial = 0;
    }
    if (yInicial < 0) {
      yInicial = 0;
    }
    std::cout << "xInicial: " << xInicial << std::endl;
    std::cout << "yInicial: " << yInicial << std::endl;
    std::vector<std::vector<std::shared_ptr<VistaObjeto>>> matrix = pista.at(0);
    for (int i = yInicial; i < yFinal; i++) {
      for (int j = xInicial; j < xFinal; j++) {
        matrix[i][j].get()->dibujar(j * 256 - deltaCamaraX, i * 256 - deltaCamaraY, 0);
      }
    }
    car.second.get()->dibujar(screenX / 2,
                              screenY / 2,
                              car.second.get()->getAngulo());
  }
  window.render();
}

void VentanaPartida::addAuto(std::shared_ptr<VistaObjeto> car) {
  autos.insert(std::pair<int, std::shared_ptr<VistaObjeto>>(0, car));

}