#ifndef _CLIENTE_H_
#define _CLIENTE_H_

#include "includes/cliente/HiloDibujador.h"

#include <string>

class Cliente {
private:
    HiloDibujador dibujador_;

public:
    Cliente();
    void correr();
    void cerrar();
    ~Cliente();
};

#endif
