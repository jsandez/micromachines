#ifndef _ESCENA_MENU_H_
#define _ESCENA_MENU_H_

#include "includes/cliente/GUI/escenas/Escena.h"

#include "includes/cliente/GUI/Animacion.h"
#include "includes/cliente/GUI/Area.h"
#include "includes/cliente/GUI/Renderizador.h"
#include "includes/cliente/GUI/Textura.h"

class EscenaMenu : public Escena {
private:
    Animacion animacion_;
public:
    EscenaMenu();
    virtual Textura dibujate(uint32_t numeroIteracion, Renderizador& renderizador, Area dimensiones) override;
};

#endif
