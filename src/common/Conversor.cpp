#include "includes/common/Conversor.h"
#include <math.h>

Conversor::Conversor(float pixelPorMetro, int pixelPorBloque) :
    pixelPorMetro(pixelPorMetro), pixelPorBloque(pixelPorBloque) {}

int Conversor::metroAPixel(float coord) {
  return round(coord * pixelPorMetro);
}

int Conversor::metroABloque(float coord) {
  return trunc(coord / pixelPorBloque);
}

float Conversor::pixelAMetro(int coord) {
  return (float) (coord / pixelPorMetro);
}