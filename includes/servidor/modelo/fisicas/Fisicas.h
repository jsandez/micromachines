#ifndef _FISICAS_H_
#define _FISICAS_H_

#include "includes/3rd-party/Box2D/Box2D.h"

class Fisicas {
private:
    b2Vec2 gravedad_;
    std::shared_ptr<b2World> mundoBox2D_;

public:
    Fisicas();
    ~Fisicas();
};

#endif
