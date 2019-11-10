#include "includes/cliente/GUI/AnimacionFactory.h"

#include <vector>

#include "includes/cliente/GUI/Textura.h"

Animacion AnimacionFactory::instanciar(int uuidAnimacion, Renderizador& renderizador) {
    std::vector<Textura> frames_;
    switch (uuidAnimacion) {
    case 1: //sorlo
        frames_.emplace_back(Textura("assets/sorlo/1_sorlo.png", renderizador));
        frames_.emplace_back(Textura("assets/sorlo/2_sorlo.png", renderizador));
        frames_.emplace_back(Textura("assets/sorlo/3_sorlo.png", renderizador));
        frames_.emplace_back(Textura("assets/sorlo/4_sorlo.png", renderizador));
        break;
    
    default:
        break;
        //throw
    }
    return Animacion(frames_);
}
