#ifndef _ESCENA_SALA_H_
#define _ESCENA_SALA_H_

#include "includes/cliente/GUI/escenas/Escena.h"

#include <memory>

#include "includes/common/ColaProtegida.h"
#include "includes/cliente/GUI/Animacion.h"
#include "includes/cliente/GUI/Area.h"
#include "includes/cliente/GUI/Renderizador.h"
#include "includes/cliente/GUI/Textura.h"

class EscenaSala : public Escena {
private:
    Animacion fondoMenu_;
    //TODO: Mover a Escena
    ColaProtegida<std::shared_ptr<EventoGUI>>& eventosGUI_;

public:
    EscenaSala(Renderizador& renderizador, ColaProtegida<std::shared_ptr<EventoGUI>>& eventosGUI, std::stack<std::shared_ptr<Escena>>& escenas);
    virtual Textura dibujate(uint32_t numeroIteracion, Area dimensiones) override;
    virtual void manejar(EventoGUI& evento) override;
    virtual void manejar(EventoGUIClick& evento) override;
    virtual void manejar(EventoGUIKeyDown& evento) override;
};

#endif
