#ifndef _CAMARA_H_
#define _CAMARA_H_
#include "includes/cliente/SdlWindow.h"
#include "includes/cliente/VistaObjeto.h"
#include <memory>
#include "includes/common/Conversor.h"

class Camara {
 private:
  Conversor &conversor;
  int width, height;
  std::shared_ptr<VistaObjeto> car;
 public:
  Camara(Conversor &conversor);
  void setWidthHeight(int width, int height);
  void setCar(std::shared_ptr<VistaObjeto> car);
  int deltaCamaraX();
  int deltaCamaraY();
};
#endif
