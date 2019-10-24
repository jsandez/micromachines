#include "includes/servidor/utils/ConfigServidor.h"

ConfigServidor& ConfigServidor::instancia() {
    static ConfigServidor config_(RUTA_CONFIG_SERVIDOR);
    return config_;
}

ConfigServidor::ConfigServidor(const std::string& rutaArchivo) :
    config_(YAML::LoadFile(rutaArchivo)) {

}

unsigned int ConfigServidor::puertoServidor() {
    return 0;
}
