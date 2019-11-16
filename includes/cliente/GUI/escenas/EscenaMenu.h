#ifndef _ESCENA_MENU_H_
#define _ESCENA_MENU_H_

#include "includes/cliente/GUI/escenas/Escena.h"

#include <memory>

#include "includes/common/ColaProtegida.h"
#include "includes/cliente/GUI/Animacion.h"
#include "includes/cliente/GUI/Area.h"
#include "includes/cliente/GUI/Renderizador.h"
#include "includes/cliente/GUI/Textura.h"

class EscenaMenu : public Escena {
private:
    Animacion fondoMenu_;
    ColaProtegida<std::shared_ptr<EventoGUI>>& eventosGUI_;

public:
    EscenaMenu(Renderizador& renderizador, ColaProtegida<std::shared_ptr<EventoGUI>>& eventosGUI, std::stack<std::shared_ptr<Escena>>& escenas);
    virtual Textura dibujate(uint32_t numeroIteracion, Area dimensiones) override;
    virtual void manejarInput(EventoGUI& evento) override;
    virtual void manejarInput(EventoGUIClick& evento) override;
    virtual void manejarInput(EventoGUIKeyDown& evento) override;
    virtual void manejar(Evento &e) override ;
};

#endif
