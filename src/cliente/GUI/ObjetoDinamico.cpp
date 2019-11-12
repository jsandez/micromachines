#include "includes/cliente/GUI/ObjetoDinamico.h"

ObjetoDinamico::ObjetoDinamico(int uuid, Renderizador &renderizador) :
    animacion_(AnimacionFactory::instanciar(uuid, renderizador)) {
  this->x = 0;
  this->y = 0;
  this->angulo = 0;
  this->vida = 100;
}

Animacion &ObjetoDinamico::getAnimacion() {
  return this->animacion_;
}

void ObjetoDinamico::mover(int x, int y, int angulo) {
  this->x = x;
  this->y = y;
  this->angulo = angulo;
}

int ObjetoDinamico::getX() const {
  return this->x;
}

int ObjetoDinamico::getY() const {
  return this->y;
}

int ObjetoDinamico::getAngulo() const {
  return this->angulo;
}

void ObjetoDinamico::setVida(int vida) {
  this->vida = vida;
}

int ObjetoDinamico::getVida() const {
  return this->vida;
}