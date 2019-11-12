#include "includes/cliente/GUI/AnimacionFactory.h"

#include <vector>
#include <string>

#include "includes/cliente/utils/ConfigCliente.h"
#include "includes/cliente/GUI/Textura.h"

Animacion AnimacionFactory::instanciar(unsigned int uuidAnimacion, Renderizador &renderizador) {
  std::vector<Textura> frames_;
  unsigned int ancho_ = 0;
  unsigned int alto_ = 0;
  switch (uuidAnimacion) {
    case UUID_ANIMACION_AUTO_ROJO:
      for (std::string &rutaArchivo : CONFIG_CLIENTE.spritesAutoRojo()) {
        frames_.emplace_back(Textura(rutaArchivo, renderizador));
      }
      ancho_ = CONFIG_CLIENTE.anchoAutoRojo();
      alto_ = CONFIG_CLIENTE.altoAutoRojo();
      break;

    case UUID_ANIMACION_FONDO_MENU:
      for (std::string &rutaArchivo : CONFIG_CLIENTE.spritesFondoMenu()) {
        frames_.emplace_back(Textura(rutaArchivo, renderizador));
      }
      ancho_ = CONFIG_CLIENTE.anchoFondoMenu();
      alto_ = CONFIG_CLIENTE.altoFondoMenu();
      break;

    default:frames_.emplace_back(Textura("assets/pistas/" + std::to_string(uuidAnimacion) + ".png", renderizador));
      ancho_ = CONFIG_CLIENTE.anchoBloquesPista();
      alto_ = CONFIG_CLIENTE.altoBloquesPista();
      break;
  }
  return Animacion(frames_, ancho_, alto_);
}
