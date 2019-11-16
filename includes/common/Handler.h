#ifndef _HANDLER_H_
#define _HANDLER_H_

#include "includes/common/eventos/Evento.h"
#include "includes/common/eventos/EventoAcelerar.h"
#include "includes/common/eventos/EventoDesacelerar.h"
#include "includes/common/eventos/EventoFrenar.h"
#include "includes/common/eventos/EventoDejarDeFrenar.h"
#include "includes/common/eventos/EventoDoblarIzquierda.h"
#include "includes/common/eventos/EventoDejarDeDoblarIzquierda.h"
#include "includes/common/eventos/EventoDoblarDerecha.h"
#include "includes/common/eventos/EventoDejarDeDoblarDerecha.h"
#include "includes/common/eventos/EventoSnapshot.h"
#include "includes/common/eventos/EventoCrearPartida.h"
#include "includes/common/eventos/EventoPartidaAgregada.h"
#include "includes/common/eventos/EventoUnirseAPartida.h"
#include "includes/common/eventos/EventoIniciarPartida.h"
#include "includes/common/eventos/EventoIDVehiculoDeJugador.h"
#include "includes/common/eventos/EventoDesconexion.h"

class Handler {
 public:
  virtual void manejar(Evento &e) = 0;
  virtual void manejar(EventoAcelerar &e);
  virtual void manejar(EventoDesacelerar &e);
  virtual void manejar(EventoFrenar &e);
  virtual void manejar(EventoDejarDeFrenar &e);
  virtual void manejar(EventoDoblarIzquierda &e);
  virtual void manejar(EventoDejarDeDoblarIzquierda &e);
  virtual void manejar(EventoDoblarDerecha &e);
  virtual void manejar(EventoDejarDeDoblarDerecha &e);
  virtual void manejar(EventoSnapshot &e);
  virtual void manejar(EventoCrearPartida &e);
  virtual void manejar(EventoPartidaAgregada &e);
  virtual void manejar(EventoUnirseAPartida &e);
  virtual void manejar(EventoIniciarPartida &e);
  virtual void manejar(EventoIDVehiculoDeJugador &e);
  virtual void manejar(EventoDesconexion &e);
};

#endif
