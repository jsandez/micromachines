#ifndef _RENDERIZADOR_H_
#define _RENDERIZADOR_H_

#include "includes/cliente/GUI/Textura.h"

//Forward declarations:
class SDL_Renderer;
class Escena;
class Ventana;

#define SDL_PRIMER_DISPONIBLE -1

class Renderizador {
private:
    SDL_Renderer* renderizadorSDL_;
    Ventana& ventana_;

    Renderizador(const Renderizador&) = delete;
    Renderizador& operator=(const Renderizador&) = delete;

    void clear();

public:
    Renderizador(Ventana& ventana);
    void dibujar(uint32_t numeroIteracion, Escena& escena);
    void setDestino(Textura& textura);
    void resetDestino();
    void dibujar(Textura& textura, Textura& canvas);
    ~Renderizador();

    SDL_Renderer* getSDL();
};

#endif
