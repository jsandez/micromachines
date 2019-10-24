#ifndef _CONFIG_SERVIDOR_H_
#define _CONFIG_SERVIDOR_H_

#define RUTA_CONFIG_SERVIDOR "/config/server_settings.yaml"

#define CONFIG_SERVIDOR ConfigServidor::instancia()

#include <string>

class ConfigServidor {
private:
    ConfigServidor(const std::string& rutaArchivo);

public:
    static ConfigServidor& instancia();
    unsigned int puertoServidor();
};

#endif
