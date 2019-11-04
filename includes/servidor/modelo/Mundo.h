#ifndef _MUNDO_H_
#define _MUNDO_H_

#include "includes/servidor/modelo/fisicas/Fisicas.h"

class Mundo {
private:
    Fisicas fisicas_;

public:
    Mundo(uint16_t uuidPista);
};

#endif
