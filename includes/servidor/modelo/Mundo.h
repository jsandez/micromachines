#ifndef _MUNDO_H_
#define _MUNDO_H_

#include <memory>
#include <stack>

#include "includes/common/Handler.h"
#include "includes/common/ColaProtegida.h"
#include "includes/servidor/modelo/fisicas/Fisicas.h"
#include "includes/servidor/modelo/entidades/Vehiculo.h"
#include "includes/common/Tile.h"
#include "includes/servidor/modelo/superficies/Superficie.h"

class Mundo : public Handler {
private:
    std::map<Tile, std::shared_ptr<Superficie>> tileASuelo_;
    //std::map<Tile, std::shared_ptr<Superficie>> tileAModificador_;
    std::stack<Tile> posicionesIniciales_;
    std::map<uint32_t, Vehiculo> jugadoresAVehiculos_;
    ColaProtegida<std::shared_ptr<Evento>> eventosOcurridos_;
    Fisicas fisicas_;
    uint8_t contadorObjetos_;
    std::map<uint32_t, uint8_t> jugadoresAIDVehiculo_;

public:
    //TODO: Mundo recibe referencia a partida para avisarle que termino.
    Mundo(uint16_t uuidPista);

    void step(uint32_t numeroIteracion);

    Cola<std::shared_ptr<Evento>>& eventosOcurridos();

    uint8_t agregarVehiculo(uint32_t uuidJugador);
    
    virtual void manejar(Evento& e) override;

    virtual void manejar(EventoAcelerar& e) override;
};

#endif
