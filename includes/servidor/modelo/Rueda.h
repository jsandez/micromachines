#ifndef _RUEDA_H_
#define _RUEDA_H_

// Forward declarations
class b2Body;
class b2World;

class Rueda {
private:
    b2Body* cuerpo;
public:
    Rueda(b2World* unMundo);
    ~Rueda();
};

#endif
