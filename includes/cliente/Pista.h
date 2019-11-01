#ifndef _PISTA_H_
#define _PISTA_H_
#include <map>
#include <includes/common/eventos/Evento.h>
#include "includes/cliente/SdlWindow.h"
#include "includes/cliente/SdlTexture.h"
#include "includes/cliente/VistaObjeto.h"
#include "includes/cliente/Bloque.h"

class Pista {
 private:
  std::map<int, std::map<Bloque, VistaObjeto>> mapa;
 public:
  Pista();
  void modificar(int profundidad, Bloque bloque);
  void modificar(Evento &e);
};

#endif
