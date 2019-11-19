#include "includes/cliente/utils/ConfigCliente.h"

#include <fstream>

ConfigCliente &ConfigCliente::instancia() {
  static ConfigCliente config_(RUTA_CONFIG_CLIENTE);
  return config_;
}

ConfigCliente::ConfigCliente(const std::string &rutaArchivo) {
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

std::string ConfigCliente::tituloVentana() {
  return std::move(json_["ventana"]["titulo"].get<std::string>());
}

unsigned int ConfigCliente::fps() {
  return json_["ventana"]["fps"].get<unsigned int>();
}

std::string ConfigCliente::host() {
  return std::move(json_["red"]["host"].get<std::string>());
}

std::string ConfigCliente::puerto() {
  return std::move(json_["red"]["puerto"].get<std::string>());
}

std::string ConfigCliente::fuente() {
  return std::move(json_["fuente"]["path"].get<std::string>());
}

unsigned int ConfigCliente::anchoBloquesPista() {
  return json_["bloques"]["ancho"].get<unsigned int>();
}

unsigned int ConfigCliente::altoBloquesPista() {
  return json_["bloques"]["alto"].get<unsigned int>();
}

unsigned int ConfigCliente::uuid(std::string nombreAnimacion) {
  return json_["animaciones"][nombreAnimacion]["uuid"].get<unsigned int>();
}

unsigned int ConfigCliente::ancho(std::string nombreAnimacion) {
  return json_["animaciones"][nombreAnimacion]["ancho"].get<unsigned int>();
}

unsigned int ConfigCliente::alto(std::string nombreAnimacion) {
  return json_["animaciones"][nombreAnimacion]["alto"].get<unsigned int>();
}

std::vector<std::string> ConfigCliente::sprites(std::string nombreAnimacion) {
  return std::move(json_["animaciones"][nombreAnimacion]["sprites"].get<std::vector<std::string>>());
}