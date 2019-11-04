#include "includes/servidor/modelo/Mundo.h"

#include <string>
#include <fstream>

#include "includes/servidor/utils/ConfigServidor.h"
#include "includes/3rd-party/jsoncpp/json.hpp"

#include <iostream>

Mundo::Mundo(uint16_t uuidPista) {
    //TODO: Aca se carga la pista json
    // TODO: Es mejor cargar todas las pistas al inicio y luego hacer un get() para no tener que ir
    // siempre a disco.
    std::string rutaPista = CONFIG_SERVIDOR.rutaPistas() + std::to_string(uuidPista) + ".json";
    std::ifstream archivoPista(rutaPista);
    Json pistaJson;
    archivoPista >> pistaJson;
    std::cout << pistaJson["capas"]["0"]["0"]["0"] << std::endl;
    std::cout << "Pista cargada\n";
}
