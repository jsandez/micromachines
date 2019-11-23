#ifndef _CARRERA_H_
#define _CARRERA_H_

#define ID_META 0

#include <map>

#include "includes/3rd-party/jsoncpp/json.hpp"
#include "includes/servidor/modelo/entidades/carrera/Checkpoint.h"

//Forward declarations
class Vehiculo;

class Carrera {
private:
    std::map<int, Checkpoint> checkpoints_;
    std::map<uint8_t, int> idsVehiculosAidsCheckpoints_;
    std::map<uint8_t, int> idsVehiculosAVueltas_;

public:
    Carrera();
    void cargarDesdeJson(Json& pistaJson);
    std::map<int, Checkpoint>& checkpoints();
    Checkpoint& ultimoCheckpointDe(Vehiculo& vehiculo);
    void setCheckpoint(Vehiculo& vehiculo, Checkpoint& checkpoint);
    void registrarVehiculo(Vehiculo& vehiculo);
};

#endif
