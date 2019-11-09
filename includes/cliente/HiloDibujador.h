#ifndef _HILO_DIBUJADOR_H_
#define _HILO_DIBUJADOR_H_

#include "includes/common/Hilo.h"

#include <string>

#include "includes/cliente/GUI/Ventana.h"
#include "includes/cliente/GUI/Renderizador.h"

class HiloDibujador : public Hilo {
private:
    Ventana ventana_;
    Renderizador renderizador_;
public:
    HiloDibujador(unsigned int anchoVentana, unsigned int altoVentana, bool pantallaCompleta, const std::string& tituloVentana);
    virtual void correr() override;
    virtual void detener() override;
};

#endif
