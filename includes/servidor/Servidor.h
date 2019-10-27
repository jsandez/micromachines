#ifndef _SERVIDOR_H_
#define _SERVIDOR_H_

#include "includes/servidor/HiloAceptador.h"

#include <string>

class Servidor {
private:
    HiloAceptador hiloAceptador_;

public:
    Servidor(const std::string& puerto);
    void correr();
    void cerrar();
};

#endif
