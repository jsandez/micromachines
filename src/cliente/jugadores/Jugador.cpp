#ifndef __JUGADOR_H__
#define __JUGADOR_H__

#include <memory>
#include "includes/common/ColaBloqueante.h"
#include "includes/common/eventos/Evento.h"
#include "includes/common/eventos/EventoAcelerar.h"
#include "includes/common/eventos/EventoDesacelerar.h"
#include "includes/common/eventos/EventoDoblarDerecha.h"
#include "includes/common/eventos/EventoDejarDeDoblarDerecha.h"
#include "includes/common/eventos/EventoDoblarIzquierda.h"
#include "includes/common/eventos/EventoDejarDeDoblarIzquierda.h"
#include "includes/common/eventos/EventoFrenar.h"
#include "includes/common/eventos/EventoDejarDeFrenar.h"


class Jugador {
private:
	ColaBloqueante<std::shared_ptr<Evento>> &eventosAEnviar_;
public:
	Jugador(ColaBloqueante<std::shared_ptr<Evento>> &eventosAEnviar) : eventosAEnviar_(eventosAEnviar) {}

	virtual void setEstado(float x, float y, uint16_t angulo){}

	virtual void empezar(){}
	virtual void terminar(){}


	virtual void acelerar(){
       std::shared_ptr<Evento>
        	eventoAcelerar = std::make_shared<EventoAcelerar>();
    	eventosAEnviar_.put(eventoAcelerar);
	}

	virtual void desacelerar(){
        std::shared_ptr<Evento>
        	eventoDesacelerar = std::make_shared<EventoDesacelerar>();
    	eventosAEnviar_.put(eventoDesacelerar);
	}

	virtual void frenar(){
		std::shared_ptr<Evento>
	        eventoFrenar = std::make_shared<EventoFrenar>();
    	eventosAEnviar_.put(eventoFrenar);
	}

	virtual void dejarDeFrenar(){
		std::shared_ptr<Evento>
			eventoDejarDeFrenar = std::make_shared<EventoDejarDeFrenar>();
		eventosAEnviar_.put(eventoDejarDeFrenar);
	}

	virtual void doblarDerecha(){
		std::shared_ptr<Evento>
	        eventoDoblarDerecha = std::make_shared<EventoDoblarDerecha>();
    	eventosAEnviar_.put(eventoDoblarDerecha);
	}

	virtual void dejarDeDoblarDerecha(){
		std::shared_ptr<Evento>
			eventoDejarDeDoblarDerecha = std::make_shared<EventoDejarDeDoblarDerecha>();
		eventosAEnviar_.put(eventoDejarDeDoblarDerecha);
	}

	virtual void doblarIzquierda(){
		std::shared_ptr<Evento>
	        eventoDoblarIzquierda = std::make_shared<EventoDoblarIzquierda>();
    	eventosAEnviar_.put(eventoDoblarIzquierda);
	}

	virtual void dejarDeDoblarIzquierda(){
		std::shared_ptr<Evento>
			eventoDejarDeDoblarIzquierda = std::make_shared<EventoDejarDeDoblarIzquierda>();
		eventosAEnviar_.put(eventoDejarDeDoblarIzquierda);
	}

};


#endif
