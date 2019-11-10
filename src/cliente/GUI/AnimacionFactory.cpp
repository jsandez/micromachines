#include "includes/cliente/GUI/AnimacionFactory.h"

#include <vector>
#include <string>

#include "includes/cliente/utils/ConfigCliente.h"
#include "includes/cliente/GUI/Textura.h"

Animacion AnimacionFactory::instanciar(unsigned int uuidAnimacion, Renderizador& renderizador) {
    std::vector<Textura> frames_;
    switch (uuidAnimacion) {
    case UUID_ANIMACION_SORLO:
        for (std::string& rutaArchivo : CONFIG_CLIENTE.spritesSorlo()) {
            frames_.emplace_back(Textura(rutaArchivo, renderizador));
        }
        break;
    
    default:
        break;
        //throw
    }
    return Animacion(frames_);
}
