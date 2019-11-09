#ifndef _ANIMACION_H_
#define _ANIMACION_H_

#include <vector>

#include "includes/cliente/GUI/Textura.h"

class Animacion {
private:
    //TODO: Hash para ciclos
    std::vector<Textura> frames_;

public:
    Animacion(std::vector<Textura>& frames);
    Textura& get(uint32_t numeroIteracion);
};

#endif
