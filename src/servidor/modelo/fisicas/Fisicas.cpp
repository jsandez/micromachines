#include "includes/servidor/modelo/fisicas/Fisicas.h"

#include "includes/servidor/utils/ConfigServidor.h"
#include "includes/common/eventos/EventoPartidaAgregada.h"

#include "includes/servidor/modelo/entidades/Vehiculo.h"
#include "includes/servidor/modelo/fisicas/transformaciones/Reubicar.h"


//TODO: Fisicas debe conocer de eventos ocurridos?
//Tiene pinta de que no. Por ende tampoco de snapshots por segundo
Fisicas::Fisicas(Cola<std::shared_ptr<Evento>>& eventosOcurridos, ContactListener& contactListener) :
    gravedad_(0, 0),
    mundoBox2D_(std::make_shared<b2World>(gravedad_)),
    frecuencia_((double)1 / (double)CONFIG_SERVIDOR.simulacionesPorSegundo()),
    iteracion_(0),
    eventosOcurridos_(eventosOcurridos) {
    
    mundoBox2D_->SetContactListener(&contactListener);
}

Fisicas::~Fisicas() {
}
void Fisicas::generarSuelo(std::map<Tile, std::shared_ptr<Superficie>>& tileASuelo) {
    //TODO: Implementar: es arena tierra y pista.
    
    for (const auto& kv : tileASuelo) {
        //uint8_t idVehiculo = mundo_.agregarVehiculo(kv.second->uuid());
        //jugadoresAVehiculos.emplace(kv.first, idVehiculo);
        b2BodyDef bodyDef;
        bodyDef.userData = kv.second.get();
        
        float anchoTile = CONFIG_SERVIDOR.anchoTile();
        float x = anchoTile*(float)kv.first.x_ + 0.5f*anchoTile; 
        float y = anchoTile*(float)kv.first.y_ + 0.5f*anchoTile;
	    bodyDef.position.Set(x, y);
        
        b2Body* cuerpo = mundoBox2D_->CreateBody(&bodyDef);
        b2PolygonShape forma;        
        forma.SetAsBox(CONFIG_SERVIDOR.ladoSuperficie(), CONFIG_SERVIDOR.ladoSuperficie());
	    b2FixtureDef caracteristicas;
	    caracteristicas.shape = &forma;
        caracteristicas.isSensor = true;
	    cuerpo->CreateFixture(&caracteristicas);
    }
}

/*void Fisicas::generarSuperficies(std::map<Tile, std::shared_ptr<Superficie>>& tileASuperficie) {
    //TODO: Implementar
}*/

void Fisicas::generarCheckpoints(std::map<unsigned int, Checkpoint>& checkpoints) {
    for (auto& kv : checkpoints) {
        b2BodyDef bodyDef;
        /*https://stackoverflow.com/questions/5377434/does-stdmapiterator-return-a-copy-of-value-or-a-value-itself*/
        bodyDef.userData = &kv.second;
        
        float anchoTile = CONFIG_SERVIDOR.anchoTile();
        
        float ancho = kv.second.ancho();
        float largo = kv.second.alto();

        float x = anchoTile*kv.second.posicion().x_;
        float y = anchoTile*kv.second.posicion().y_;

        bodyDef.position.Set(x, y);
        
        b2Body* cuerpo = mundoBox2D_->CreateBody(&bodyDef);
        b2PolygonShape forma;        
        forma.SetAsBox(ancho/2.0f, largo/2.0f);
	    b2FixtureDef caracteristicas;
	    caracteristicas.shape = &forma;
        caracteristicas.isSensor = true;
	    cuerpo->CreateFixture(&caracteristicas);
    }
}
void Fisicas::acelerar(uint8_t uuidVehiculo) {
    vehiculos_.at(uuidVehiculo)->acelerando();
}

void Fisicas::desacelerar(uint8_t uuidVehiculo) {
    vehiculos_.at(uuidVehiculo)->desacelerando();
}

void Fisicas::frenar(uint8_t uuidVehiculo) {
    vehiculos_.at(uuidVehiculo)->frenando();
}

void Fisicas::dejarDeFrenar(uint8_t uuidVehiculo) {
    vehiculos_.at(uuidVehiculo)->dejandoDeFrenar();
}

void Fisicas::doblarIzquierda(uint8_t uuidVehiculo) {
    vehiculos_.at(uuidVehiculo)->doblandoIzquierda();
}

void Fisicas::dejarDeDoblarIzquierda(uint8_t uuidVehiculo) {
    vehiculos_.at(uuidVehiculo)->dejandoDeDoblarIzquierda();
}

void Fisicas::doblarDerecha(uint8_t uuidVehiculo) {
    vehiculos_.at(uuidVehiculo)->doblandoDerecha();
}

void Fisicas::dejarDeDoblarDerecha(uint8_t uuidVehiculo) {
    vehiculos_.at(uuidVehiculo)->dejandoDeDoblarDerecha();
}

void Fisicas::agregarVehiculo(Vehiculo& vehiculo, Posicion& posicion) {
    vehiculos_.emplace(vehiculo.uuid(), std::make_shared<B2DVehiculo>(mundoBox2D_.get(), vehiculo));
    b2Vec2 posicionBox2D = {posicion.x_, posicion.y_};
    vehiculos_.at(vehiculo.uuid())->getB2D()->SetTransform(posicionBox2D, (float)posicion.anguloDeg_);
}

Posicion Fisicas::getPosicionDe(uint8_t idCuerpo) {
    
    b2Body* cuerpoFisico = vehiculos_.at(idCuerpo)->getB2D();
    b2Vec2 posicion = cuerpoFisico->GetPosition();
    float32 angulo = cuerpoFisico->GetAngle();
    int anguloDeg = (int)(angulo*RADTODEG) % 360;
    anguloDeg *= -1;
    if (anguloDeg < 0) {
        anguloDeg += 360;
    }
    return Posicion(posicion.x, posicion.y, anguloDeg);
}

void Fisicas::step(uint32_t numeroIteracion) {
    //TODO: Todos haran step
    //Acá se alteran los cuerpos físicos.
    for (const auto& kv : vehiculos_) {
        kv.second->step();
    }
    uint32_t escala = numeroIteracion - iteracion_;
    float tiempoAtranscurrir = (float)escala * frecuencia_;
    mundoBox2D_->Step(tiempoAtranscurrir, CONFIG_SERVIDOR.iteracionesVelocidad(), CONFIG_SERVIDOR.iteracionesPosicion());
    iteracion_ = numeroIteracion;
    //TODO: Aplicar transformaciones y encolar eventos pertinentes.
    while(!transformaciones_.empty()) {
        std::shared_ptr<Transformacion> t = transformaciones_.front();
        t->aplicar();
        transformaciones_.pop();
    }
}

void Fisicas::reubicar(Vehiculo& vehiculo, Posicion& posicion) {
    b2Body* cuerpoVehiculo = vehiculos_.at(vehiculo.uuid())->getB2D();
    std::shared_ptr<Transformacion> t = std::make_shared<Reubicar>(*this, cuerpoVehiculo, posicion);
    transformaciones_.push(t);
}
