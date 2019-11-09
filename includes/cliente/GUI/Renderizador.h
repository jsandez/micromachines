#ifndef _RENDERIZADOR_H_
#define _RENDERIZADOR_H_

#include <memory>

#include "includes/cliente/GUI/Textura.h"

//Forward declarations:
class SDL_Renderer;
class Escena;
class Ventana;

#define SDL_PRIMER_DISPONIBLE -1

class Renderizador {
private:
    SDL_Renderer* renderizadorSDL_;
    std::shared_ptr<Ventana> ventana_;

    Renderizador(const Renderizador&) = delete;
    Renderizador& operator=(const Renderizador&) = delete;

    void clear();

public:
    Renderizador(std::shared_ptr<Ventana> ventana);
    void dibujar(uint32_t numeroIteracion, Escena& escena);
    void setDestino(Textura& textura);
    void resetDestino();
    void d();
    ~Renderizador();

    SDL_Renderer* getSDL();
};

#endif
