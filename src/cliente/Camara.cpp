#include "includes/cliente/Camara.h"

Camara::Camara(Conversor &conversor) :
    conversor(conversor) {}

void Camara::setWidthHeight(int width, int height) {
  this->width = width;
  this->height = height;
}
void Camara::setCar(std::shared_ptr<VistaObjeto> car) {
  this->car = car;
}

int Camara::deltaCamaraX() {
  int deltaCamaraX = car->getX();
  if (deltaCamaraX < width / 2) {
    car.get()->mover((width / 2) - deltaCamaraX, 0, 0);
    deltaCamaraX = width / 2;
  }
  int limiteFinalX = conversor.bloqueAPixel(15) - (width / 2);
  if (deltaCamaraX > limiteFinalX) {
    car.get()->mover(-(deltaCamaraX - limiteFinalX), 0, 0);
    deltaCamaraX = limiteFinalX;
  }
  return deltaCamaraX;
}

int Camara::deltaCamaraY() {
  int deltaCamaraY = car.get()->getY();
  if (deltaCamaraY < height / 2) {
    car.get()->mover(0, (height / 2) - deltaCamaraY, 0);
    deltaCamaraY = height / 2;
  }
  int limiteFinalY = conversor.bloqueAPixel(15) - (height / 2);
  if (deltaCamaraY > limiteFinalY) {
    car.get()->mover(0, -(deltaCamaraY - limiteFinalY), 0);
    deltaCamaraY = limiteFinalY;
  }
  return deltaCamaraY;
}

