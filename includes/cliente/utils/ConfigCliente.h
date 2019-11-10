#ifndef _CONFIG_CLIENTE_H_
#define _CONFIG_CLIENTE_H_

#define RUTA_CONFIG_CLIENTE "config/client_settings.json"

#define CONFIG_CLIENTE ConfigCliente::instancia()

#include <string>
#include <vector>

#include "includes/3rd-party/jsoncpp/json.hpp"

class ConfigCliente {
private:
    ConfigCliente(const std::string& rutaArchivo);
    Json json_;

public:
    static ConfigCliente& instancia();
    unsigned int anchoVentana();
    unsigned int altoVentana();
    bool pantallaCompleta();
    std::string tituloVentana();

    unsigned int uuidSorlo();
    std::vector<std::string> spritesSorlo();
};

#endif
