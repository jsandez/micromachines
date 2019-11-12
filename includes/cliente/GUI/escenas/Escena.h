#ifndef _ESCENA_H_
#define _ESCENA_H_

#include <stack>
#include <memory>

#include "includes/cliente/GUI/EventoGUIHandler.h"

#include "includes/cliente/GUI/Renderizador.h"
#include "includes/cliente/GUI/Textura.h"

class Escena : public EventoGUIHandler {
protected:
    std::stack<std::shared_ptr<Escena>>& escenas_;
    Renderizador& renderizador_;

public:
    Escena(std::stack<std::shared_ptr<Escena>>& escenas, Renderizador& renderizador);
    virtual Textura dibujate(uint32_t numeroIteracion, Area dimensiones) = 0;
    virtual ~Escena();
};

#endif
