#ifndef _POSICION_H_
#define _POSICION_H_

#include <cstdint>

class Posicion {
public:
    uint16_t x_;
    uint16_t y_;
    uint16_t anguloDeg_;

    Posicion(uint16_t x, uint16_t y, uint16_t anguloDeg);
};

#endif
