#ifndef _ANIMACION_H_
#define _ANIMACION_H_

#include <vector>
#include <map>

#include "includes/cliente/GUI/Textura.h"

class Animacion {
private:
    unsigned int ancho_;
    unsigned int alto_;

    std::vector<int> iterations_;
    std::vector<Textura> frames_;

    void loadFramesByIteration();

public:
    Animacion(std::vector<Textura>& frames, unsigned int ancho, unsigned int alto);
    Textura& get(uint32_t numeroIteracion);

    unsigned int ancho();
    unsigned int alto();
};

#endif
