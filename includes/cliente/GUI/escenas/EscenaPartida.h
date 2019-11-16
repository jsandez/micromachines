#ifndef _ESCENA_PARTIDA_H_
#define _ESCENA_PARTIDA_H_

#include "includes/cliente/GUI/escenas/Escena.h"

#include <memory>

#include "includes/common/ColaProtegida.h"
#include "includes/common/Conversor.h"
#include "includes/cliente/GUI/Animacion.h"
#include "includes/cliente/GUI/Area.h"
#include "includes/cliente/GUI/Renderizador.h"
#include "includes/cliente/GUI/Textura.h"
#include "includes/cliente/GUI/Pista.h"
#include "includes/cliente/GUI/Camara.h"

class EscenaPartida : public Escena {
 private:
  ColaProtegida<std::shared_ptr<EventoGUI>> &eventosGUI_;
  Pista pista;
  Conversor conversor;
  Camara camara;
  int id_car, screenX, screenY;
 public:
  EscenaPartida(Renderizador &renderizador,
                ColaProtegida<std::shared_ptr<EventoGUI>> &eventosGUI,
                std::stack<std::shared_ptr<Escena>> &escenas, ColaBloqueante<std::shared_ptr<Evento>> &eventosAEnviar_);
  virtual Textura dibujate(uint32_t numeroIteracion, Area dimensiones) override;
  virtual void manejarInput(EventoGUI &evento) override;
  virtual void manejarInput(EventoGUIClick &evento) override;
  virtual void manejarInput(EventoGUIKeyDown &evento) override;
  virtual void manejar(Evento &e) override;
  virtual void manejar(EventoSnapshot &e) override;
  virtual void manejar(EventoIDVehiculoDeJugador &e) override;

};
#endif
