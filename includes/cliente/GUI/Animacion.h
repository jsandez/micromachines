#ifndef _ANIMACION_H_
#define _ANIMACION_H_

#include <vector>

class Animacion {
private:
    //TODO: Hash para ciclos
    std::vector<Textura> frames_;

public:
    Animacion(std::vector<Textura>& frames);
};

#endif
