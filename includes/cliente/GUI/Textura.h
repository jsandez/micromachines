#ifndef _TEXTURA_H_
#define _TEXTURA_H_

#include <string>

// Forward Declarations:
class SDL_Texture;

class Renderizador;

class Textura {
private:
    SDL_Texture* texturaSDL_;

    Renderizador& renderizador_;

    Textura(const Textura&) = delete;

    Textura& operator=(const Textura&) = delete;

public:
    Textura(const std::string& rutaArchivo, Renderizador& renderizador);
    Textura(Textura&& other);
    Textura& operator=(Textura&& other);
    ~Textura();

    SDL_Texture* getSDL();
};

#endif
