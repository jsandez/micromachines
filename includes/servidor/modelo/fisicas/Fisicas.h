#ifndef _FISICAS_H_
#define _FISICAS_H_

#include "includes/3rd-party/Box2D/Box2D.h"

class Fisicas {
private:
    b2World* mundoBox2D_;
    b2Vec2 gravedad_;

public:
    Fisicas();
    ~Fisicas();
};

#endif
