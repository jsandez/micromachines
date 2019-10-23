#ifndef _AUTO_H_
#define _AUTO_H_
#include "SdlWindow.h"
#include "SdlTexture.h"

class Car {
 private:
  int width;
  int height;
  //The X and Y offsets of the dot
  int mPosX, mPosY;
  //The velocity of the dot
  int mVelX, mVelY;
 public:
  //Maximum axis velocity of the dot
  static const int DOT_VEL = 10;
  Car(int width, int height);
  void dibujar(SdlWindow &sdl_window);
  void manejarEvento(SDL_Event& e);
  void manejar();
};

#endif
