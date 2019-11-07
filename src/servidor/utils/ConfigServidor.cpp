#include "includes/servidor/utils/ConfigServidor.h"

#include <fstream>

ConfigServidor& ConfigServidor::instancia() {
    static ConfigServidor config_(RUTA_CONFIG_SERVIDOR);
    return config_;
}

ConfigServidor::ConfigServidor(const std::string& rutaArchivo) {
    std::ifstream archivo(rutaArchivo);
    archivo >> json_;
    tilesTierra_ = json_["tiles"]["tilesTierra"].get<std::vector<int>>();
    tilesPista_ = json_["tiles"]["tilesPista"].get<std::vector<int>>();
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

std::vector<int>& ConfigServidor::tilesTierra() {
    return tilesTierra_;
}

std::vector<int>& ConfigServidor::tilesPista() {
    return tilesPista_;
}

int ConfigServidor::tileArena() {
    return json_["tiles"]["arena"].get<int>();
}

int ConfigServidor::tileBarro() {
    return json_["tiles"]["barro"].get<int>();
}

int ConfigServidor::tileAceite() {
    return json_["tiles"]["aceite"].get<int>();
}

int ConfigServidor::tileVacio() {
    return json_["tiles"]["vacio"].get<int>();
}

uint32_t ConfigServidor::iteracionesPorSegundo() {
    return json_["fisicas"]["simulacionesPorSegundo"].get<uint32_t>();
}
