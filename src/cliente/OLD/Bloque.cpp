#include "includes/cliente/Bloque.h"

Bloque::Bloque(int x, int y) : x(x), y(y) {}

int Bloque::getX() const {
  return x;
}

int Bloque::getY() const {
  return y;
}
