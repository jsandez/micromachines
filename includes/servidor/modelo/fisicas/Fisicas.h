#ifndef _FISICAS_H_
#define _FISICAS_H_

#include <map>

#include "includes/3rd-party/Box2D/Box2D.h"
#include "includes/common/Tile.h"
#include "includes/common/Cola.h"
#include "includes/common/eventos/Evento.h"
#include "includes/servidor/modelo/superficies/Superficie.h"
#include "includes/servidor/modelo/entidades/Vehiculo.h"
#include "includes/servidor/modelo/movimiento/Posicion.h"
#include "includes/servidor/modelo/fisicas/B2DVehiculo.h"

class Fisicas {
private:
    b2Vec2 gravedad_;
    std::shared_ptr<b2World> mundoBox2D_;
    std::map<uint8_t, b2Body*> colisionables_;
    std::map<uint8_t, std::shared_ptr<B2DVehiculo>> vehiculos_;
    double frecuencia_;
    uint32_t iteracion_;
    Cola<std::shared_ptr<Evento>>& eventosOcurridos_;
    
public:
    Fisicas(Cola<std::shared_ptr<Evento>>& eventosOcurridos);
    ~Fisicas();
    void generarSuelo(std::map<Tile, std::shared_ptr<Superficie>>& tileASuelo);
    //void generarSuperficies(std::map<Tile, std::shared_ptr<Superficie>>& tileASuperficie);
    void step(uint32_t numeroIteracion);
    void agregarVehiculo(Vehiculo& vehiculo, Posicion& posicion);
    void acelerar(uint8_t uuidVehiculo);
    void desacelerar(uint8_t uuidVehiculo);
    void frenar(uint8_t uuidVehiculo);
    void dejarDeFrenar(uint8_t uuidVehiculo);
    void doblarIzquierda(uint8_t uuidVehiculo);
    void dejarDeDoblarIzquierda(uint8_t uuidVehiculo);
    void doblarDerecha(uint8_t uuidVehiculo);
    void dejarDeDoblarDerecha(uint8_t uuidVehiculo);
};

#endif
