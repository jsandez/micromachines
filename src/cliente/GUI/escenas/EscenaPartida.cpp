#include <iostream>
#include <includes/cliente/utils/ConfigCliente.h>
#include <includes/cliente/GUI/Texto.h>
#include "includes/cliente/GUI/escenas/EscenaPartida.h"
#include "includes/cliente/GUI/Area.h"

// TODO: Refactorizar
void EscenaPartida::dibujarInterfaz(int iteracion) {
  Texto vida(CONFIG_CLIENTE.texto("salud"),
             CONFIG_CLIENTE.tamanioTexto("salud"),
             renderizador_,
             UUID_TEXTO_BLANCO);
  Animacion salud
      (AnimacionFactory::instanciar(UUID_ANIMACION_SALUD, this->renderizador_));
  Area areaVida =
      Area(CONFIG_CLIENTE.margenX("salud") * CONFIG_CLIENTE.anchoVentana(),
           CONFIG_CLIENTE.margenY("salud") * CONFIG_CLIENTE.altoVentana(),
           CONFIG_CLIENTE.anchoTexto("salud"),
           salud.alto());
  renderizador_.dibujarTexto(vida, areaVida);
  std::shared_ptr<ObjetoDinamico> principalCar = pista.obtenerObjeto(id_car);
  Area areaSalud = Area(CONFIG_CLIENTE.anchoTexto("salud") + 20,
                        CONFIG_CLIENTE.margenY("salud")
                            * CONFIG_CLIENTE.altoVentana(),
                        round(principalCar.get()->getVida() * salud.ancho()
                                  / 100),
                        salud.alto());
  renderizador_.dibujar(salud.get(iteracion), areaSalud);
}

EscenaPartida::EscenaPartida(Renderizador &renderizador,
                             ColaProtegida<std::shared_ptr<EventoGUI>> &eventosGUI,
                             std::stack<std::shared_ptr<Escena>> &escenas,
                             ColaBloqueante<std::shared_ptr<Evento>> &eventosAEnviar_,
                             EventoPartidaIniciada &estadoInicial,
                             Sonido &musicaAmbiente) :
    Escena(escenas, renderizador, eventosAEnviar_, musicaAmbiente),
    eventosGUI_(eventosGUI),
    pista("assets/pistas/1.json", renderizador),
    conversor(CONFIG_CLIENTE.pixelPorMetro(), CONFIG_CLIENTE.pixelPorBloque()),
    camara(conversor, pista, renderizador) {
  this->musicaAmbiente.stop();
  const std::map<uint8_t, datosVehiculo_>
      &idsADatosVehiculos = estadoInicial.estadoInicial_.idsADatosVehiculos_;
  //FIXME: Esto no esta bueno
  int vehiculoActual = 800;
  for (const auto &kv : idsADatosVehiculos) {
    uint8_t id = kv.first;
    std::shared_ptr<ObjetoDinamico> vehiculo =
        std::make_shared<ObjetoDinamico>(vehiculoActual,
                                         renderizador,
                                         CONFIG_CLIENTE.musicaMotor(),
                                         true);
    pista.agregarObjeto(id, vehiculo);
    //FIXME: ESTO TAMBIEN ESTA FEO, LA PISTA DEBERIA DEJAR AGREGAR EN X; Y; ANGULO; TAMBIEN CON VIDA?
    int xCoord = conversor.metroAPixel(kv.second.xCoord_);
    int yCoord = conversor.metroAPixel(kv.second.yCoord_);
    uint16_t angulo = kv.second.angulo_;

    pista.obtenerObjeto(id)->mover(xCoord, yCoord, angulo);
    vehiculoActual += 10;
  }

  camara.setCar(pista.obtenerObjeto(estadoInicial.idDelVehiculo_));
  this->id_car = estadoInicial.idDelVehiculo_;
}

Textura EscenaPartida::dibujate(uint32_t numeroIteracion, Area dimensiones) {
  Area nueva = Area(0, 0, dimensiones.ancho() * 2, dimensiones.alto() * 2);
  Textura miTextura(renderizador_, nueva);
  renderizador_.setDestino(miTextura);
  this->camara.setWidthHeight(nueva.ancho(), nueva.alto());
  camara.dibujarPista(numeroIteracion);
  std::shared_ptr<ObjetoDinamico> principalCar = pista.obtenerObjeto(id_car);
  Animacion &animacion = principalCar.get()->getAnimacion();
  Area areaFondo =
      Area(nueva.ancho() / 2 - (float) animacion.ancho() / 2.0f,
           nueva.alto() / 2 - (float) animacion.alto() / 2.0f,
           animacion.ancho(),
           animacion.alto());
  renderizador_.dibujar(animacion.get(numeroIteracion),
                        areaFondo,
                        principalCar.get()->getAngulo(),
                        false);
  camara.dibujarObjetos(id_car, numeroIteracion);
  dibujarInterfaz(numeroIteracion);
  return std::move(miTextura);
}

void EscenaPartida::manejarInput(EventoGUI &evento) {
  evento.actualizar((EventoGUIHandler &) (*this));
}

void EscenaPartida::manejarInput(EventoGUIClick &evento) {}

void EscenaPartida::manejarInput(EventoGUIKeyDown &evento) {
  if (evento.getTecla() == TECLA_FULLSCREEN) {
    renderizador_.toggleFullScreen();
  } else if (evento.getTecla() == TECLA_ESC) {
    escenas_.pop();
  } else if (evento.getTecla() == TECLA_A) {
    std::shared_ptr<Evento> eventoAcelerar = std::make_shared<EventoAcelerar>();
    eventosAEnviar_.put(eventoAcelerar);
  } else if (evento.getTecla() == TECLA_Z) {
    std::shared_ptr<Evento> eventoFrenar = std::make_shared<EventoFrenar>();
    eventosAEnviar_.put(eventoFrenar);
  } else if (evento.getTecla() == TECLA_IZQ) {
    std::shared_ptr<Evento>
        eventoDoblarIzq = std::make_shared<EventoDoblarIzquierda>();
    eventosAEnviar_.put(eventoDoblarIzq);
  } else if (evento.getTecla() == TECLA_DER) {
    std::shared_ptr<Evento>
        eventoDoblarDer = std::make_shared<EventoDoblarDerecha>();
    eventosAEnviar_.put(eventoDoblarDer);
  } else if (evento.getTecla() == TECLA_C) {
    std::shared_ptr<Evento>
        eventoIniciarPartida = std::make_shared<EventoIniciarPartida>();
    eventosAEnviar_.put(eventoIniciarPartida);
  }
}

void EscenaPartida::manejarInput(EventoGUIKeyUp &evento) {
  if (evento.getTecla() == TECLA_A) {
    std::shared_ptr<Evento>
        eventoDesacelerar = std::make_shared<EventoDesacelerar>();
    eventosAEnviar_.put(eventoDesacelerar);
  } else if (evento.getTecla() == TECLA_Z) {
    std::shared_ptr<Evento>
        eventoDejarDeFrenar = std::make_shared<EventoDejarDeFrenar>();
    eventosAEnviar_.put(eventoDejarDeFrenar);
  } else if (evento.getTecla() == TECLA_IZQ) {
    std::shared_ptr<Evento> eventoDejarDeDoblarIzq =
        std::make_shared<EventoDejarDeDoblarIzquierda>();
    eventosAEnviar_.put(eventoDejarDeDoblarIzq);
  } else if (evento.getTecla() == TECLA_DER) {
    std::shared_ptr<Evento>
        eventoDejarDeDoblarDer = std::make_shared<EventoDejarDeDoblarDerecha>();
    eventosAEnviar_.put(eventoDejarDeDoblarDer);
  }
}

void EscenaPartida::manejar(Evento &e) {
  e.actualizar((Handler &) (*this));
}

void EscenaPartida::manejar(EventoSnapshot &e) {
  std::map<uint8_t, datosVehiculo_> datos = e.idsADatosVehiculos_;
  for (const auto &kv : datos) {
    float posX = this->conversor.metroAPixel(kv.second.xCoord_);
    float posY = this->conversor.bloqueAPixel(pista.getSizeY())
        - this->conversor.metroAPixel(kv.second.yCoord_);
    this->pista.obtenerObjeto(kv.first).get()->mover(posX,
                                                     posY,
                                                     kv.second.angulo_);
    this->pista.obtenerObjeto(kv.first).get()->setVida(kv.second.salud_);
  }
}
