#ifndef _CREADORTEXTURAS_H_
#define _CREADORTEXTURAS_H_
#include <memory>
#include "includes/cliente/SdlWindow.h"
#include "includes/cliente/VistaObjeto.h"

class CreadorTexturas {
 private:
  SdlTexture tierra;
  SdlTexture pasto;
  SdlTexture asfalto_recto;
  SdlTexture asfalto_curva;
  SdlTexture car;
  SdlTexture salud;
  SdlTexture boost;
  SdlTexture piedra;
  SdlTexture aceite;
  SdlTexture barro;

 public:
  CreadorTexturas(SdlWindow &sdl_window);
  std::shared_ptr<VistaObjeto> crear(int id);
};
#endif
