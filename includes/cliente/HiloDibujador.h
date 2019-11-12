#ifndef _HILO_DIBUJADOR_H_
#define _HILO_DIBUJADOR_H_

#include "includes/common/Hilo.h"

#include <stack>
#include <memory>

#include "includes/common/eventos/Evento.h"
#include "includes/common/ColaProtegida.h"
#include "includes/cliente/GUI/Ventana.h"
#include "includes/cliente/GUI/Renderizador.h"
#include "includes/cliente/GUI/eventos/EventoGUI.h"

class HiloDibujador : public Hilo {
private:
    Ventana& ventana_;
    Renderizador& renderizador_;
    ColaProtegida<std::shared_ptr<Evento>> eventos_;
    ColaProtegida<std::shared_ptr<EventoGUI>>& eventosGUI_;
    //TODO: Abstraer en "Escenario" ?
    std::stack<std::shared_ptr<Escena>> escenas_;

public:
    HiloDibujador(Ventana& ventana, Renderizador& renderizador, ColaProtegida<std::shared_ptr<EventoGUI>>& eventosGUI);
    virtual void correr() override;
    virtual void detener() override;

    ColaProtegida<std::shared_ptr<Evento>>& eventosEntrantes();
};

#endif
