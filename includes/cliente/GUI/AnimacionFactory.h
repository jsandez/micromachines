#ifndef _ANIMACION_FACTORY_H_
#define _ANIMACION_FACTORY_H_

#include <vector>

#include "includes/cliente/GUI/Textura.h"
#include "includes/cliente/GUI/Renderizador.h"
#include "includes/cliente/GUI/Animacion.h"

#define UUID_ANIMACION_SALUD 200
#define UUID_ANIMACION_FONDO_MENU 700
#define UUID_ANIMACION_AUTO_ROJO 800
#define UUID_ANIMACION_AUTO_AMARILLO 810
#define UUID_ANIMACION_AUTO_NEGRO 820
#define UUID_ANIMACION_AUTO_AZUL 830
#define UUID_ANIMACION_AUTO_VERDE 840
#define UUID_ANIMACION_EXPLOSION 900
#define UUID_ANIMACION_CAJAS_SALUD 1000
#define UUID_ANIMACION_BOOST 1100
#define UUID_ANIMACION_PIEDRA 1200
#define UUID_ANIMACION_ACEITE 1300
#define UUID_ANIMACION_BARRO 1400

class AnimacionFactory {
    
public:
    static Animacion instanciar(unsigned int uuidAnimacion, Renderizador& renderizador);
};

#endif
