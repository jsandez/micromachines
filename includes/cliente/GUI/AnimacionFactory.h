#ifndef _ANIMACION_FACTORY_H_
#define _ANIMACION_FACTORY_H_

#include <vector>

#include "includes/cliente/GUI/Textura.h"
#include "includes/cliente/GUI/Renderizador.h"
#include "includes/cliente/GUI/Animacion.h"

class AnimacionFactory {
    
public:
    static Animacion instanciar(int uuidAnimacion, Renderizador& renderizador);
};

#endif
