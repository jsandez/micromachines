#include "includes/servidor/modelo/entidades/carrera/Carrera.h"

#include "includes/servidor/modelo/entidades/Vehiculo.h"
#include "includes/common/Conversor.h"
Carrera::Carrera() {
}

void Carrera::cargarDesdeJson(Json& pistaJson) {
    int cantidadCheckpoints = pistaJson["checkpoints"]["cantidad"].get<int>();
    uint16_t largoY = pistaJson["dimensiones"]["y"].get<uint16_t>();
        
    //TODO: Cargo checkpoints, meta es aparte (?) ¿Lo es?
    for (int i = 0; i < cantidadCheckpoints; ++i) {
        float x = pistaJson["checkpoints"][std::to_string(i)]["x"].get<float>();
        float y = largoY - pistaJson["checkpoints"][std::to_string(i)]["y"].get<float>();
        float ancho = pistaJson["checkpoints"][std::to_string(i)]["ancho"].get<float>();
        float largo = pistaJson["checkpoints"][std::to_string(i)]["largo"].get<float>();
        uint16_t angulo = pistaJson["checkpoints"][std::to_string(i)]["anguloRespawn"].get<uint16_t>();
        Posicion posicion(Conversor::tileAMetro(x), Conversor::tileAMetro(y), angulo);
        checkpoints_.emplace(i, Checkpoint(*this, i, (i+1) % cantidadCheckpoints, ancho, largo, posicion));
    }
}

std::map<int, Checkpoint>& Carrera::checkpoints() {
    return checkpoints_;
}

Checkpoint& Carrera::ultimoCheckpointDe(Vehiculo& vehiculo) {
    return checkpoints_.at(idsVehiculosAidsCheckpoints_.at(vehiculo.uuid()));
}

#include <iostream>
void Carrera::setCheckpoint(Vehiculo& vehiculo, Checkpoint& checkpoint) {
    idsVehiculosAidsCheckpoints_[vehiculo.uuid()] = checkpoint.id();
    if (checkpoint.id() == ID_META) {
        idsVehiculosAVueltas_[vehiculo.uuid()]++;
        std::cout << "Lleva " << idsVehiculosAVueltas_[vehiculo.uuid()] << " vueltas\n";
    } 
}

void Carrera::registrarVehiculo(Vehiculo& vehiculo) {
    idsVehiculosAidsCheckpoints_[vehiculo.uuid()] = 0;
    idsVehiculosAVueltas_[vehiculo.uuid()] = 0;
}
