#ifndef _CLIENTE_H_
#define _CLIENTE_H_

#include <string>

#include "includes/cliente/GUI/Ventana.h"
#include "includes/cliente/GUI/Renderizador.h"
#include "includes/cliente/HiloDibujador.h"

class Cliente {
private:
    Ventana ventana_;
    Renderizador renderizador_;
    HiloDibujador dibujador_;

public:
    Cliente(unsigned int anchoVentana, unsigned int altoVentana, bool pantallaCompleta, const std::string& tituloVentana);
    void correr();
    void cerrar();
    ~Cliente();
};

#endif
