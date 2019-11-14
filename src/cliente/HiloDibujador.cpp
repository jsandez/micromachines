#include "includes/cliente/HiloDibujador.h"

#include "includes/cliente/GUI/escenas/EscenaMenu.h"

#include "includes/cliente/utils/ConfigCliente.h"

#include <SDL2/SDL.h>
#include <includes/common/Cronometro.h>

HiloDibujador::HiloDibujador(Ventana &ventana,
                             Renderizador &renderizador,
                             ColaProtegida<std::shared_ptr<EventoGUI>> &eventosGUI) :
    ventana_(ventana),
    renderizador_(renderizador),
    eventosGUI_(eventosGUI) {

  escenas_.emplace(std::make_shared<EscenaMenu>(renderizador_, eventosGUI_, escenas_));
}

void HiloDibujador::correr() {
  double frecuencia = (double) 1 / (double) CONFIG_CLIENTE.fps();
  frecuencia *= 1000;
  Cronometro c;
  double t1 = c.ahora();
  //TODO: Resetear cada vez que se cambia de escena
  uint32_t iteracion = 0;
  while (seguirCorriendo_) {
    Escena &escenaActual = *escenas_.top().get();
    renderizador_.dibujar(iteracion, escenaActual);
    double t2 = c.ahora();
    double resto = frecuencia - (t2 - t1);
    if (resto < 0) {
      double atraso = -resto;
      double perdidos = atraso - std::fmod(atraso, frecuencia);
      resto = frecuencia - std::fmod(atraso, frecuencia);
      t1 += perdidos;
      iteracion += std::floor(perdidos / frecuencia);
    }
    dormir(resto);
    t1 += frecuencia;
    iteracion += 1;
    //FIXME: Se arregla haciendo que el metodo manejar evento devuelva true si hay que continuar.
    // También se puede chequear al hacer pop que no se esté quedando sin escenas
    bool obtenido = false;
    std::shared_ptr<EventoGUI> evento;
    while ((obtenido = eventosGUI_.get(evento))) {
      escenaActual.manejar(*evento.get());
    }
  }
}

void HiloDibujador::detener() {
  seguirCorriendo_ = false;
}

ColaProtegida<std::shared_ptr<Evento>> &HiloDibujador::eventosEntrantes() {
  return eventos_;
}
