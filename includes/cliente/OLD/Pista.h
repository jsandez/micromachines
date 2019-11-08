#ifndef _PISTA_H_
#define _PISTA_H_
#include <map>
#include <memory>
#include <vector>
#include "includes/cliente/VistaObjeto.h"
#include "includes/cliente/SdlTexture.h"

class Pista {
 private:
  std::map<int, std::vector<std::vector<std::shared_ptr<VistaObjeto>>>> mapa;
  int size_x, size_y;
 public:
  Pista(int capas, int size_x, int size_y);
  void agregarBloque(int capa, int x, int y, std::shared_ptr<VistaObjeto> vista);
  std::shared_ptr<VistaObjeto> getBloque(int capa, int x, int y) const;
  int getSizeX() const;
  int getSizeY() const;
};

#endif
