#ifndef _CARRERA_H_
#define _CARRERA_H_

#include <map>

#include "includes/3rd-party/jsoncpp/json.hpp"
#include "includes/servidor/modelo/entidades/carrera/Checkpoint.h"

class Carrera {
private:
    std::map<int, Checkpoint> checkpoints_;

public:
    Carrera(Json& pistaJson);
    std::map<int, Checkpoint>& checkpoints();
};

#endif
