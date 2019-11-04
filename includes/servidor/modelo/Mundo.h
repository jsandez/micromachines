#ifndef _MUNDO_H_
#define _MUNDO_H_

#include "includes/servidor/modelo/fisicas/Fisicas.h"
#include "includes/common/Tile.h"

class Mundo {
private:
    Fisicas fisicas_;
    std::map<Tile, uint16_t> tileASuelo_;
    std::map<Tile, uint16_t> tileASuperficie_;

public:
    Mundo(uint16_t uuidPista);
};

#endif
