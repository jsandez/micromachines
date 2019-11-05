#include "includes/cliente/Camara.h"

Camara::Camara(Conversor &conversor, Pista &pista, std::map<int, std::shared_ptr<VistaObjeto>> &objetosDinamicos) :
    conversor(conversor), pista(pista), objetosDinamicos(objetosDinamicos) {
  xInicial = 0;
  xFinal = 0;
  yInicial = 0;
  yFinal = 0;
}

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
  int limiteFinalX = conversor.bloqueAPixel(pista.getSizeX()) - (width / 2);
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
  int limiteFinalY = conversor.bloqueAPixel(pista.getSizeY()) - (height / 2);
  if (deltaCamaraY > limiteFinalY) {
    car.get()->mover(0, -(deltaCamaraY - limiteFinalY), 0);
    deltaCamaraY = limiteFinalY;
  }
  return deltaCamaraY;
}

void Camara::dibujarPista() {
  int deltaX = deltaCamaraX();
  int deltaY = deltaCamaraY();
  int posCarX = conversor.pixelABloque(deltaX);
  int posCarY = conversor.pixelABloque(deltaY);
  xInicial = posCarX - (conversor.pixelABloque(width / 2) + 1);
  xFinal = posCarX + (conversor.pixelABloque(width / 2) + 2);
  yInicial = posCarY - (conversor.pixelABloque(height / 2) + 1);
  yFinal = posCarY + (conversor.pixelABloque(height / 2) + 2);
  if (xInicial < 0) {
    xInicial = 0;
  }
  if (yInicial < 0) {
    yInicial = 0;
  }
  if (xFinal > pista.getSizeX()) {
    xFinal = pista.getSizeX();
  }
  if (yFinal > pista.getSizeY()) {
    yFinal = pista.getSizeY();
  }
  for (int i = yInicial; i < yFinal; i++) {
    for (int j = xInicial; j < xFinal; j++) {
      pista.getBloque(0, i, j).get()->dibujar(j * 256 - (deltaX - width / 2),
                                              i * 256 - (deltaY - height / 2),
                                              0);
    }
  }
}

void Camara::dibujarObjetos(int car_id) {
  for (std::pair<int, std::shared_ptr<VistaObjeto>> car :objetosDinamicos) {
    if (car.first != car_id) {
      int bloqueCarX = conversor.pixelABloque(car.second.get()->getX());
      int bloqueCarY = conversor.pixelABloque(car.second.get()->getY());
      if (bloqueCarX >= xInicial &&
          bloqueCarX <= xFinal &&
          bloqueCarY >= yInicial &&
          bloqueCarY <= yFinal) {
        car.second.get()->dibujar(car.second.get()->getX() - (deltaCamaraX() - width / 2),
                                  car.second.get()->getY() - (deltaCamaraY() - height / 2),
                                  car.second.get()->getAngulo());
      }
    }
  }
}
