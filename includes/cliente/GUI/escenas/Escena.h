#ifndef _ESCENA_H_
#define _ESCENA_H_

#include "includes/cliente/GUI/Renderizador.h"
#include "includes/cliente/GUI/Textura.h"

class Escena {
private:

public:
    virtual Textura dibujate(uint32_t numeroIteracion, Renderizador& renderizador, Area dimensiones) = 0;
    virtual ~Escena();
};

#endif
