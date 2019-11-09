#ifndef _RENDERIZADOR_H_
#define _RENDERIZADOR_H_

//Forward declarations:
class SDL_Renderer;
class Ventana;
class Textura;

#define SDL_PRIMER_DISPONIBLE -1

class Renderizador {
private:
    SDL_Renderer* renderizadorSDL_;
    Ventana& ventana_;

public:
    Renderizador(Ventana& ventana);
    ~Renderizador();

    SDL_Renderer* getSDL();
};

#endif
