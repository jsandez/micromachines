#ifndef _CAMARA_H_
#define _CAMARA_H_
#include "includes/cliente/SdlWindow.h"
#include "includes/cliente/VistaObjeto.h"
#include <memory>
#include "includes/common/Conversor.h"

class Camara{
private:
    int width,height;
    Conversor& conversor;
    std::shared_ptr<VistaObjeto> car;
public:
    Camara(int width, int height,Conversor& conversor);
    void setCar(std::shared_ptr<VistaObjeto> car);
    int deltaCamaraX();
    int deltaCamaraY();
};
#endif
