#ifndef _CLIENTE_H_
#define _CLIENTE_H_

#include "includes/cliente/Ventana.h"
#include "includes/cliente/Renderizador.h"

class Cliente {
private:
    Ventana ventana_;
    Renderizador renderizador_;
public:
    Cliente();
    void correr();
    void cerrar();
};

#endif
