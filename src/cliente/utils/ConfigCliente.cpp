#include "includes/cliente/utils/ConfigCliente.h"

#include <fstream>

ConfigCliente& ConfigCliente:: instancia() {
    static ConfigCliente config_(RUTA_CONFIG_CLIENTE);
    return config_;
}

ConfigCliente::ConfigCliente(const std::string& rutaArchivo) {
    std::ifstream archivo(rutaArchivo);
    archivo >> json_;
}

unsigned int ConfigCliente::anchoVentana() {
    return json_["ventana"]["ancho"].get<unsigned int>();
}

unsigned int ConfigCliente::altoVentana() {
    return json_["ventana"]["alto"].get<unsigned int>();
}

bool ConfigCliente::pantallaCompleta() {
    return json_["ventana"]["pantallaCompleta"].get<bool>();
}
