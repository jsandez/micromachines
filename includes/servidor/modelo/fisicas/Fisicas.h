#ifndef _FISICAS_H_
#define _FISICAS_H_

// Forward declarations
class b2World;

class Fisicas {
private:
    b2World* mundoBox2D_;
    b2Vec2 gravedad_;

public:
    Fisicas();
};

#endif
