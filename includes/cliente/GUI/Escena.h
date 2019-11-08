#ifndef _ESCENA_H_
#define _ESCENA_H_

#include "includes/cliente/GUI/Ventana.h"
#include "includes/cliente/GUI/Renderizador.h"

class Escena {
private:
    Ventana& ventana_;
    Renderizador& renderizador_;
    
public:
    Escena(Ventana& ventana, Renderizador& renderizador);
    void dibujar(uint32_t numeroIteracion);
};

#endif
