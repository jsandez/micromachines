#include "includes/servidor/modelo/fisicas/Fisicas.h"

Fisicas::Fisicas() :
    gravedad_(0, 0),
    mundoBox2D_(std::make_shared<b2World>(gravedad_)) {
}

Fisicas::~Fisicas() {
}
