#ifndef _CONFIG_CLIENTE_H_
#define _CONFIG_CLIENTE_H_

#define RUTA_CONFIG_CLIENTE "config/client_settings.json"

#define CONFIG_CLIENTE ConfigCliente::instancia()

#include <string>
#include <vector>

#include "includes/3rd-party/jsoncpp/json.hpp"

class ConfigCliente {
 private:
  ConfigCliente(const std::string &rutaArchivo);
  Json json_;

 public:
  static ConfigCliente &instancia();

  unsigned int anchoVentana();
  unsigned int altoVentana();
  bool pantallaCompleta();
  std::string tituloVentana();
  unsigned int fps();

  std::string host();
  std::string puerto();

  std::string fuente();

  std::string musicaAmbiente();
  std::string musicaMotor();
  std::string musicaExplosion();

  unsigned int volumenAmbiente();

  unsigned int anchoBloquesPista();
  unsigned int altoBloquesPista();

  unsigned int uuid(std::string nombreAnimacion);
  unsigned int ancho(std::string nombreAnimacion);
  unsigned int alto(std::string nombreAnimacion);
  std::vector<std::string> sprites(std::string nombreAnimacion);

  unsigned int anchoGrabadora();
  unsigned int altoGrabadora();
  std::string formatoGrabadora();
  uint32_t fpsGrabadora();
  unsigned int bitrateGrabadora();
};

#endif
