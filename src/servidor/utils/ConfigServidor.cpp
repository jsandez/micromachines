#include "includes/servidor/utils/ConfigServidor.h"

#include <fstream>

ConfigServidor& ConfigServidor::instancia() {
    static ConfigServidor config_(RUTA_CONFIG_SERVIDOR);
    return config_;
}

ConfigServidor::ConfigServidor(const std::string& rutaArchivo) {
    std::ifstream archivo(rutaArchivo);
    archivo >> json_;
}

std::string ConfigServidor::puertoServidor() {
    return json_["red"]["puerto"].get<std::string>();
}

unsigned int ConfigServidor::maxClientesEnEspera() {
    return json_["red"]["maxClientesEnEspera"].get<unsigned int>();
}

std::string ConfigServidor::rutaPistas() {
    return json_["rutaPistas"].get<std::string>();
}
