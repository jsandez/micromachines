#ifndef _SERVIDOR_H_
#define _SERVIDOR_H_

#include "includes/servidor/HiloAceptador.h"

#include <string>

#define CARACTER_SALIR 'q'

class Servidor {
private:
    bool seguirCorriendo_;
    HiloAceptador hiloAceptador_;

public:
    Servidor(const std::string& puerto);
    void correr();
    void cerrar();
};

#endif
