#ifndef _VENTANA_H_
#define _VENTANA_H_

#include <string>

//Forward declarations:
class SDL_Window;

class Ventana {
private:
    SDL_Window* ventanaSDL_;
    unsigned int ancho_;
    unsigned int alto_;

public:
    Ventana(unsigned int ancho, unsigned int alto, bool pantallaCompleta, const std::string& tituloVentana);
    ~Ventana();

    SDL_Window* getSDL();

private:
    SDL_Window* crearConFullScreen(unsigned int ancho, unsigned int alto, const std::string& tituloPantalla);
    SDL_Window* crearSinFullScreen(unsigned int ancho, unsigned int alto, const std::string& tituloPantalla);
};

#endif
