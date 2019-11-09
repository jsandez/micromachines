#ifndef _TEXTURA_H_
#define _TEXTURA_H_

#include <string>
#include <memory>

// Forward Declarations:
class SDL_Texture;

class Renderizador;

class Textura {
private:
    SDL_Texture* texturaSDL_;

    std::shared_ptr<Renderizador>  renderizador_;

    Textura(const Textura&) = delete;

    Textura& operator=(const Textura&) = delete;

public:
    Textura(const std::string& rutaArchivo, std::shared_ptr<Renderizador> renderizador);
    Textura(Textura&& otraTextura);
    Textura& operator=(Textura&& otraTextura);
    ~Textura();

    SDL_Texture* getSDL();
};

#endif
