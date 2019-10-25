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

unsigned int ConfigServidor::puertoServidor() {
    return json_["red"]["puerto"].get<unsigned int>();
}
