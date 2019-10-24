#ifndef _CONFIG_SERVIDOR_H_
#define _CONFIG_SERVIDOR_H_

#define RUTA_CONFIG_SERVIDOR "/config/server_settings.json"

#define CONFIG_SERVIDOR ConfigServidor::instancia()

#include <string>

#include "includes/3rd-party/jsoncpp/json.hpp"

class ConfigServidor {
private:
    ConfigServidor(const std::string& rutaArchivo);
    

public:
    static ConfigServidor& instancia();
    unsigned int puertoServidor();
};

#endif
