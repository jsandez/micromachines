#ifndef _CONFIG_SERVIDOR_H_
#define _CONFIG_SERVIDOR_H_

#define RUTA_CONFIG_SERVIDOR "config/server_settings.json"

#define CONFIG_SERVIDOR ConfigServidor::instancia()

#define Json nlohmann::json

#include <string>

#include "includes/3rd-party/jsoncpp/json.hpp"

class ConfigServidor {
private:
    ConfigServidor(const std::string& rutaArchivo);
    Json json_;    

public:
    static ConfigServidor& instancia();
    std::string puertoServidor();
    unsigned int maxClientesEnEspera();
};

#endif
