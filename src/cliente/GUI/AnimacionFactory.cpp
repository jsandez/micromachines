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
    case UUID_ANIMACION_SALUD:
      for (std::string &rutaArchivo : CONFIG_CLIENTE.sprites("salud")) {
        frames_.emplace_back(Textura(rutaArchivo, renderizador));
      }
      ancho_ = CONFIG_CLIENTE.ancho("salud");
      alto_ = CONFIG_CLIENTE.alto("salud");
      break;
    case UUID_ANIMACION_AUTO_ROJO:
      for (std::string &rutaArchivo : CONFIG_CLIENTE.sprites("autoRojo")) {
        frames_.emplace_back(Textura(rutaArchivo, renderizador));
      }
      ancho_ = CONFIG_CLIENTE.ancho("autoRojo");
      alto_ = CONFIG_CLIENTE.alto("autoRojo");
      break;
    case UUID_ANIMACION_AUTO_AMARILLO:
      for (std::string &rutaArchivo : CONFIG_CLIENTE.sprites("autoAmarillo")) {
        frames_.emplace_back(Textura(rutaArchivo, renderizador));
      }
      ancho_ = CONFIG_CLIENTE.ancho("autoAmarillo");
      alto_ = CONFIG_CLIENTE.alto("autoAmarillo");
      break;
    case UUID_ANIMACION_AUTO_NEGRO:
      for (std::string &rutaArchivo : CONFIG_CLIENTE.sprites("autoNegro")) {
        frames_.emplace_back(Textura(rutaArchivo, renderizador));
      }
      ancho_ = CONFIG_CLIENTE.ancho("autoNegro");
      alto_ = CONFIG_CLIENTE.alto("autoNegro");
      break;
    case UUID_ANIMACION_AUTO_AZUL:
      for (std::string &rutaArchivo : CONFIG_CLIENTE.sprites("autoAzul")) {
        frames_.emplace_back(Textura(rutaArchivo, renderizador));
      }
      ancho_ = CONFIG_CLIENTE.ancho("autoAzul");
      alto_ = CONFIG_CLIENTE.alto("autoAzul");
      break;
    case UUID_ANIMACION_AUTO_VERDE:
      for (std::string &rutaArchivo : CONFIG_CLIENTE.sprites("autoVerde")) {
        frames_.emplace_back(Textura(rutaArchivo, renderizador));
      }
      ancho_ = CONFIG_CLIENTE.ancho("autoVerde");
      alto_ = CONFIG_CLIENTE.alto("autoVerde");
      break;

    case UUID_ANIMACION_FONDO_MENU:
      for (std::string &rutaArchivo : CONFIG_CLIENTE.sprites("fondoMenu")) {
        frames_.emplace_back(Textura(rutaArchivo, renderizador));
      }
      ancho_ = CONFIG_CLIENTE.ancho("fondoMenu");
      alto_ = CONFIG_CLIENTE.alto("fondoMenu");
      break;

    case UUID_ANIMACION_EXPLOSION:
      for (std::string &rutaArchivo : CONFIG_CLIENTE.sprites("explosion")) {
        frames_.emplace_back(Textura(rutaArchivo, renderizador));
      }
      ancho_ = CONFIG_CLIENTE.ancho("explosion");
      alto_ = CONFIG_CLIENTE.alto("explosion");
      break;

    case UUID_ANIMACION_CAJAS_SALUD:
      for (std::string &rutaArchivo : CONFIG_CLIENTE.sprites("cajaSalud")) {
        frames_.emplace_back(Textura(rutaArchivo, renderizador));
      }
      ancho_ = CONFIG_CLIENTE.ancho("cajaSalud");
      alto_ = CONFIG_CLIENTE.alto("cajaSalud");
      break;

    case UUID_ANIMACION_BOOST:
      for (std::string &rutaArchivo : CONFIG_CLIENTE.sprites("boost")) {
        frames_.emplace_back(Textura(rutaArchivo, renderizador));
      }
      ancho_ = CONFIG_CLIENTE.ancho("boost");
      alto_ = CONFIG_CLIENTE.alto("boost");
      break;

    case UUID_ANIMACION_PIEDRA:
      for (std::string &rutaArchivo : CONFIG_CLIENTE.sprites("piedra")) {
        frames_.emplace_back(Textura(rutaArchivo, renderizador));
      }
      ancho_ = CONFIG_CLIENTE.ancho("piedra");
      alto_ = CONFIG_CLIENTE.alto("piedra");
      break;

    case UUID_ANIMACION_ACEITE:
      for (std::string &rutaArchivo : CONFIG_CLIENTE.sprites("aceite")) {
        frames_.emplace_back(Textura(rutaArchivo, renderizador));
      }
      ancho_ = CONFIG_CLIENTE.ancho("aceite");
      alto_ = CONFIG_CLIENTE.alto("aceite");
      break;

    case UUID_ANIMACION_BARRO:
      for (std::string &rutaArchivo : CONFIG_CLIENTE.sprites("barro")) {
        frames_.emplace_back(Textura(rutaArchivo, renderizador));
      }
      ancho_ = CONFIG_CLIENTE.ancho("barro");
      alto_ = CONFIG_CLIENTE.alto("barro");
      break;

    default:frames_.emplace_back(Textura("assets/pistas/" + std::to_string(uuidAnimacion) + ".png", renderizador));
      ancho_ = CONFIG_CLIENTE.anchoBloquesPista();
      alto_ = CONFIG_CLIENTE.altoBloquesPista();
      break;
  }
  return Animacion(frames_, ancho_, alto_);
}
