#ifndef _MUNDO_H_
#define _MUNDO_H_

#include <memory>
#include <queue>

#include "includes/common/Handler.h"
#include "includes/common/ColaProtegida.h"
#include "includes/servidor/modelo/fisicas/Fisicas.h"
#include "includes/servidor/modelo/fisicas/ContactListener.h"
#include "includes/servidor/modelo/entidades/Vehiculo.h"
#include "includes/common/Tile.h"
#include "includes/servidor/modelo/superficies/Superficie.h"
#include "includes/servidor/modelo/entidades/carrera/Carrera.h"

class Mundo : public Handler {
private:
    std::map<Tile, std::shared_ptr<Superficie>> tileASuelo_;
    //std::map<Tile, std::shared_ptr<Superficie>> tileAModificador_;
    std::queue<Posicion> posicionesIniciales_;
    std::map<uint32_t, Vehiculo> jugadoresAVehiculos_;
    ColaProtegida<std::shared_ptr<Evento>> eventosOcurridos_;
    Fisicas fisicas_;
    uint8_t contadorObjetos_;
    std::map<uint32_t, uint8_t> jugadoresAIDVehiculo_;
    unsigned int snapshotsEnviadosPorSegundo_;
    ContactListener contactListener_;
    Carrera carrera_;

    std::map<uint8_t, datosVehiculo_> serializarEstado();

public:
    //TODO: Mundo recibe referencia a partida para avisarle que termino.
    Mundo(uint16_t uuidPista);

    ~Mundo();

    void step(uint32_t numeroIteracion);

    Cola<std::shared_ptr<Evento>>& eventosOcurridos();

    uint8_t agregarVehiculo(uint32_t uuidJugador);

    std::map<uint8_t, datosVehiculo_> getEstadoInicial();
    
    virtual void manejar(Evento& e) override;
    virtual void manejar(EventoAcelerar& e) override;
    virtual void manejar(EventoDesacelerar& e) override;
    virtual void manejar(EventoFrenar& e) override;
    virtual void manejar(EventoDejarDeFrenar& e) override;
    virtual void manejar(EventoDoblarIzquierda& e) override;
    virtual void manejar(EventoDejarDeDoblarIzquierda& e) override;
    virtual void manejar(EventoDoblarDerecha& e) override;
    virtual void manejar(EventoDejarDeDoblarDerecha& e) override;
};

#endif
