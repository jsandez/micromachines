#ifndef _CAJA_VIDA_H_
#define _CAJA_VIDA_H_

#include "includes/servidor/modelo/entidades/Modificador.h"

class CajaVida : public Modificador {
public:
    CajaVida(uint8_t uuid);
    virtual int getTipo() override;
};

#endif
