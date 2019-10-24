#include "includes/cliente/Car.h"

Car::Car(int width, int height, SdlTexture &sdl_texture) :
    width(width), height(height), texture(sdl_texture) {
  //Initialize the offsets
  mPosX = 0;
  mPosY = 0;

  //Initialize the velocity
  mVelX = 0;
  mVelY = 0;
}

void Car::dibujar(SdlWindow &sdl_window, int x, int y) {
  Area src_area(0, 0, 463, 1010);
  Area dest_area(x, y, this->width, this->height);
  this->texture.render(src_area, dest_area, (double) -90, SDL_FLIP_NONE);
}

void Car::manejarEvento(SDL_Event &e) {
  //If a key was pressed
  if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
    //Adjust the velocity
    switch (e.key.keysym.sym) {
      case SDLK_UP: mVelY -= DOT_VEL;
        break;
      case SDLK_DOWN: mVelY += DOT_VEL;
        break;
      case SDLK_LEFT: mVelX -= DOT_VEL;
        break;
      case SDLK_RIGHT: mVelX += DOT_VEL;
        break;
    }
  }
    //If a key was released
  else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
    //Adjust the velocity
    switch (e.key.keysym.sym) {
      case SDLK_UP: mVelY += DOT_VEL;
        break;
      case SDLK_DOWN: mVelY -= DOT_VEL;
        break;
      case SDLK_LEFT: mVelX += DOT_VEL;
        break;
      case SDLK_RIGHT: mVelX -= DOT_VEL;
        break;
    }
  }
}

void Car::manejar() {
  //Move the dot left or right
  mPosX += mVelX;

  //If the dot went too far to the left or right
  if ((mPosX < 0) || (mPosX + width > 1920)) {
    //Move back
    mPosX -= mVelX;
  }

  //Move the dot up or down
  mPosY += mVelY;

  //If the dot went too far up or down
  if ((mPosY < 0) || (mPosY + height > 1080)) {
    //Move back
    mPosY -= mVelY;
  }
}

int Car::getPosX() {
  return mPosX;
}

int Car::getPosY() {
  return mPosY;
}