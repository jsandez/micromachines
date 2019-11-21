#ifndef _SONIDO_H_
#define _SONIDO_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include <string>

class Sonido {
 private:
  Mix_Chunk* efectoSonido;

 public:
  Sonido(std::string filename);
  void play(bool loop);
  void stop();
  void setVolume(int volume);
  ~Sonido();
};
#endif
