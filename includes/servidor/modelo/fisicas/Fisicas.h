#ifndef _FISICAS_H_
#define _FISICAS_H_

#include <map>

#include "includes/3rd-party/Box2D/Box2D.h"
#include "includes/common/Tile.h"

class Fisicas {
private:
    b2Vec2 gravedad_;
    std::shared_ptr<b2World> mundoBox2D_;
    std::map<uint16_t, b2Body*> colisionables_;

public:
    Fisicas();
    ~Fisicas();
    void generarSuelo(std::map<Tile, uint16_t>& tileASuelo);
    void generarSuperficies(std::map<Tile, uint16_t>& tileASuperficie);
};

#endif
