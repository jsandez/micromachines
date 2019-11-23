#ifndef _ESCENA_LOBBY_H_
#define _ESCENA_LOBBY_H_

#include <includes/common/ColaProtegida.h>
#include "includes/cliente/GUI/escenas/Escena.h"
#include "includes/cliente/GUI/Boton.h"

class EscenaLobby : public Escena {
 private:
  Animacion fondoMenu_;
  ColaProtegida<std::shared_ptr<EventoGUI>> &eventosGUI_;
  std::map<int, std::shared_ptr<Boton>> botones;

  void inicializarBotones();
  void dibujarBotones(int iteracion);
  void handlerBotones(int uuid);
 public:
  EscenaLobby(Renderizador &renderizador,
              ColaProtegida<std::shared_ptr<EventoGUI>> &eventosGUI,
              std::stack<std::shared_ptr<Escena>> &escenas,
              ColaBloqueante<std::shared_ptr<Evento>> &eventosAEnviar_,
              Sonido &musicaAmbiente);
  virtual Textura dibujate(uint32_t numeroIteracion, Area dimensiones) override;
  virtual void manejarInput(EventoGUI &evento) override;
  virtual void manejarInput(EventoGUIClick &evento) override;
  virtual void manejarInput(EventoGUIKeyDown &evento) override;
  virtual void manejarInput(EventoGUIKeyUp &evento) override;
  virtual void manejar(Evento &e) override;
  virtual void manejar(EventoPartidaIniciada &estadoInicial) override;
};
#endif
