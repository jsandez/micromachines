#ifndef __COMPUTADORA_H__
#define __COMPUTADORA_H__


#include <iostream>
#include <fstream>

#include "includes/3rd-party/jsoncpp/json.hpp"
#include "./Jugador.cpp"
#include "includes/common/Hilo.h"
#include "includes/3rd-party/lua/LuaInterprete.hpp"
#include "includes/cliente/utils/ConfigCliente.h"


class Computadora : public Jugador, Hilo {
private:
	LuaInterpreter lua;
public:
	Computadora(ColaBloqueante<std::shared_ptr<Evento>> &eventosAEnviar, std::string fileName) : Jugador(eventosAEnviar){
      	std::string rutaPista = std::move(fileName);
		std::ifstream archivoPista(rutaPista);
		Json pistaJson;
		archivoPista >> pistaJson;

        int size_x = pistaJson["dimensiones"]["x"].get<uint16_t>();
 		int size_y = pistaJson["dimensiones"]["y"].get<uint16_t>(); 


		lua.init_script(CONFIG_CLIENTE.rutaLuaScript().c_str());
	    for (uint16_t i = 0; i < size_x; i++) {
	      for (uint16_t j = 0; j < size_y; j++) {
		        if (pistaJson["capas"]["pista"][std::to_string(i)][std::to_string(j)].get<int>() > 0){
		    		lua.call_function("insert_road_block", 2, 0);
		        	lua << i;
		        	lua << (size_y - j - 1); 	
		        }
    		}
    	}

	}

	virtual void setEstado(float x, float y, uint16_t angulo) override {}
	virtual void empezar() override {
		Hilo::iniciar();
	}

	virtual void terminar() override {
		detener();
		Hilo::join();
	}

	virtual void detener() override {
		this->seguirCorriendo_ = false;
	}

	virtual void correr() override {


	}



// eventos humano
	virtual void acelerar(){}
	virtual void desacelerar(){}
	virtual void frenar(){}
	virtual void dejarDeFrenar(){}
	virtual void doblarDerecha(){}
	virtual void dejarDeDoblarDerecha(){}
	virtual void doblarIzquierda(){}
	virtual void dejarDeDoblarIzquierda(){}
};

#endif
