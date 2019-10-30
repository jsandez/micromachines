#ifndef _CREADORTEXTURAS_H_
#define _CREADORTEXTURAS_H_
#include <memory>
#include "includes/cliente/SdlWindow.h"
#include "includes/cliente/VistaObjeto.h"

class CreadorTexturas {
 private:
  SdlTexture tierra;
  SdlTexture pasto;
  SdlTexture pista;
  SdlTexture curva;
  SdlTexture agua;
  SdlTexture roca;
  SdlTexture bush1;
  SdlTexture bush2;
  SdlTexture tribuna1;
  SdlTexture tribuna2;
 public:
  CreadorTexturas(SdlWindow &sdl_window);
  std::shared_ptr<VistaObjeto> crear(int id, int x, int y);
};
#endif
