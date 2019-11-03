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
  texturasPista.insert(std::pair<int, std::shared_ptr<VistaObjeto>>(100, creador_texturas.crear(100)));
  texturasPista.insert(std::pair<int, std::shared_ptr<VistaObjeto>>(102, creador_texturas.crear(102)));
  std::vector<std::vector<std::shared_ptr<VistaObjeto>>> matrix;
  std::vector<std::shared_ptr<VistaObjeto>> arrayTierra;
  std::vector<std::shared_ptr<VistaObjeto>> arrayAsfalto;
  for (int j = 0; j < 4; j++) {
    arrayTierra.push_back(texturasPista.at(100));
  }
  matrix.push_back(arrayTierra);
  for (int j = 0; j < 4; j++) {
    arrayAsfalto.push_back(texturasPista.at(102));
  }
  matrix.push_back(arrayAsfalto);
  pista.insert(std::pair<int, std::vector<std::vector<std::shared_ptr<VistaObjeto>>>>(0, matrix));
}

void VentanaPartida::dibujar() {
  std::vector<std::vector<std::shared_ptr<VistaObjeto>>> matrix = pista.at(0);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      matrix[i][j].get()->dibujar(j * 256, i * 256, 0);
    }
  }
  for (std::pair<int, std::shared_ptr<VistaObjeto>> car :autos) {
    car.second.get()->dibujar(car.second.get()->getX(), car.second.get()->getY(), car.second.get()->getAngulo());
  }
  window.render();
}

void VentanaPartida::addAuto(std::shared_ptr<VistaObjeto> car) {
  autos.insert(std::pair<int, std::shared_ptr<VistaObjeto>>(0, car));

}