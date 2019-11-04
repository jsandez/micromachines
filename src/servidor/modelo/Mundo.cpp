#include "includes/servidor/modelo/Mundo.h"

#include <string>
#include <fstream>

#include "includes/servidor/utils/ConfigServidor.h"
#include "includes/3rd-party/jsoncpp/json.hpp"

Mundo::Mundo(uint16_t uuidPista) {
    //TODO: Aca se carga la pista json
    std::string rutaPista = CONFIG_SERVIDOR.rutaPistas() + std::to_string(uuidPista) + ".json";
    std::ifstream archivoPista(rutaPista);
    Json pistaJson;
    archivoPista >> pistaJson;
}
