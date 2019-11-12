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

  std::string host();
  std::string puerto();

  unsigned int uuidSorlo();
  unsigned int anchoSorlo();
  unsigned int altoSorlo();
  std::vector<std::string> spritesSorlo();

  unsigned int uuidAutoRojo();
  unsigned int anchoAutoRojo();
  unsigned int altoAutoRojo();
  std::vector<std::string> spritesAutoRojo();

  unsigned int uuidAutoBlanco();
  unsigned int anchoAutoBlanco();
  unsigned int altoAutoBlanco();
  std::vector<std::string> spritesAutoBlanco();

  unsigned int uuidAutoNegro();
  unsigned int anchoAutoNegro();
  unsigned int altoAutoNegro();
  std::vector<std::string> spritesAutoNegro();

  unsigned int uuidAutoAzul();
  unsigned int anchoAutoAzul();
  unsigned int altoAutoAzul();
  std::vector<std::string> spritesAutoAzul();

  unsigned int uuidFondoMenu();
  unsigned int anchoFondoMenu();
  unsigned int altoFondoMenu();
  std::vector<std::string> spritesFondoMenu();

  unsigned int anchoBloquesPista();
  unsigned int altoBloquesPista();
};

#endif
