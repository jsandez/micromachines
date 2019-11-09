#ifndef _RENDERIZADOR_H_
#define _RENDERIZADOR_H_

#include <memory>

//Forward declarations:
class SDL_Renderer;
class Escena;
class Ventana;

#define SDL_PRIMER_DISPONIBLE -1

class Renderizador {
private:
    SDL_Renderer* renderizadorSDL_;
    std::shared_ptr<Ventana> ventana_;

public:
    Renderizador(std::shared_ptr<Ventana> ventana);
    void dibujar(uint32_t numeroIteracion, Escena& escena);
    ~Renderizador();

    SDL_Renderer* getSDL();
};

#endif
