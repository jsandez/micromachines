#ifndef _ANIMACION_FACTORY_H_
#define _ANIMACION_FACTORY_H_

#include <vector>

#include "includes/cliente/GUI/Textura.h"
#include "includes/cliente/GUI/Renderizador.h"
#include "includes/cliente/GUI/Animacion.h"

#define UUID_BOTON_CREAR_PARTIDA 300
#define UUID_BOTON_UNIRSE_A_PARTIDA 310
#define UUID_BOTON_SALIR 320
#define UUID_BOTON_JUGAR 330
#define UUID_BOTON_ATRAS 340
#define UUID_BOTON_INICIAR_PARTIDA 350
#define UUID_BOTON_LISTO 360
#define UUID_BOTON_MENU 370
#define UUID_BOTON_VACIO 380
#define UUID_ANIMACION_SALUD 400
#define UUID_ANIMACION_FONDO_MENU 700
#define UUID_ANIMACION_FONDO_SALA 710
#define UUID_ANIMACION_AUTO_ROJO 800
#define UUID_ANIMACION_AUTO_AMARILLO 810
#define UUID_ANIMACION_AUTO_NEGRO 820
#define UUID_ANIMACION_AUTO_AZUL 830
#define UUID_ANIMACION_AUTO_VERDE 840
#define UUID_ANIMACION_AUTO_OTRO 850
#define UUID_ANIMACION_EXPLOSION 900
#define UUID_ANIMACION_CAJAS_SALUD 1000
#define UUID_ANIMACION_BOOST 1100
#define UUID_ANIMACION_PIEDRA 1200
#define UUID_ANIMACION_ACEITE 1300
#define UUID_ANIMACION_BARRO 1400

#define UUID_ANIMACION_PASTO 106

class AnimacionFactory {
    
public:
    static Animacion instanciar(unsigned int uuidAnimacion, Renderizador& renderizador);
};

#endif
