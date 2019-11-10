#ifndef _ANIMACION_H_
#define _ANIMACION_H_

#include <vector>

#include "includes/cliente/GUI/Textura.h"

class Animacion {
private:
    unsigned int ancho_;
    unsigned int alto_;
    //TODO: Hash para ciclos
    std::vector<Textura> frames_;    

public:
    Animacion(std::vector<Textura>& frames, unsigned int ancho, unsigned int alto);
    Textura& get(uint32_t numeroIteracion);

    unsigned int ancho();
    unsigned int alto();
};

#endif
