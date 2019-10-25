#include "includes/cliente/Car.h"

Car::Car(int width, int height, SdlTexture &sdl_texture) :
    VistaObjeto(width, height, sdl_texture) {}

void Car::dibujar(int x, int y) {
  Area src_area(0, 0, 463, 1010);
  Area dest_area(x, y, this->width, this->height);
  this->textura.render(src_area, dest_area, (double) -90, SDL_FLIP_NONE);
}

void Car::mover(int x, int y) {}

void Car::rotar(int rotacion) {}
