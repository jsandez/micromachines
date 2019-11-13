#include "includes/servidor/modelo/Mundo.h"

#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#include "includes/servidor/utils/ConfigServidor.h"
#include "includes/3rd-party/jsoncpp/json.hpp"
#include "includes/common/Tile.h"
#include "includes/common/Conversor.h"
#include "includes/servidor/modelo/superficies/SuperficieFactory.h"
#include "includes/servidor/modelo/movimiento/Posicion.h"

//TODO: Crear conversor de coordenadas?
//Forward declaration
static void cargarSuelo(uint16_t largoX, uint16_t largoY, std::map<Tile, std::shared_ptr<Superficie>>& tilesASuelo, Json& pistaJson);
static void cargarPosicionesIniciales(uint16_t largoX, uint16_t largoY, std::stack<Tile>& tiles_, Json& pistaJson);
//TODO: implementar
//static void cargarModificadores(uint16_t largoX, uint16_t largoY, std::map<Tile, std::shared_ptr<Superficie>>& tilesAModificadores, Json& pistaJson);

Mundo::Mundo(uint16_t uuidPista) :
    fisicas_(eventosOcurridos_) {
    //TODO: Es mejor cargar todas las pistas al inicio y luego hacer un get() para no tener que ir
    // siempre a disco.
    std::string rutaPista = CONFIG_SERVIDOR.rutaPistas() + std::to_string(uuidPista) + ".json";
    std::ifstream archivoPista(rutaPista);
    Json pistaJson;
    archivoPista >> pistaJson;
    uint16_t largoX = pistaJson["dimensiones"]["x"].get<uint16_t>();
    uint16_t largoY = pistaJson["dimensiones"]["y"].get<uint16_t>();

    cargarSuelo(largoX, largoY, tileASuelo_, pistaJson);
    cargarPosicionesIniciales(largoX, largoY, posicionesIniciales_, pistaJson);
    //cargarSuperficies(x, y, tileAModificador_, pistaJson);

    //TODO: Cargar posiciones de Vehículos
    
    fisicas_.generarSuelo(tileASuelo_);
    //fisicas_.generarSuperficies(tileAModificador_);
}

void Mundo::step(uint32_t numeroIteracion) {
    fisicas_.step(numeroIteracion);
    //TODO: Encolar la serializacion
}

Cola<std::shared_ptr<Evento>>& Mundo::eventosOcurridos() {
    return eventosOcurridos_;
}

void Mundo::agregarVehiculo(uint32_t uuidJugador) {
    //TODO: En cual de los casilleros?
    Tile tile = posicionesIniciales_.top();
    float xMetros = Conversor::tileAMetro(tile.x_);
    float yMetros = Conversor::tileAMetro(tile.y_);
    Posicion posicion(xMetros, yMetros, 0.0);
    //TODO: Refactor, usar move semantics
    std::shared_ptr<Vehiculo> vehiculo = std::make_shared<Vehiculo>(CONFIG_SERVIDOR.velocidadMaxVehiculoAdelante(),
            CONFIG_SERVIDOR.velocidadMaxVehiculoAtras(),
            CONFIG_SERVIDOR.aceleracionVehiculo(),
            CONFIG_SERVIDOR.maniobrabilidadVehiculo(),
            CONFIG_SERVIDOR.agarreVehiculo(),
            CONFIG_SERVIDOR.saludVehiculo());
    jugadoresAVehiculos_[uuidJugador] = vehiculo;
    fisicas_.agregarVehiculo(*vehiculo.get(), posicion);
    posicionesIniciales_.pop();
}

void Mundo::manejar(Evento& e) {
    e.actualizar(*this);
}

void Mundo::manejar(EventoAcelerar& e) {
    uint32_t jugador = e.uuidRemitente();
    fisicas_.acelerar(jugadoresAVehiculos_[jugador]->uuid());
}

// El sistema de referencia de la pista está arriba a la izquierda,
// mientras que en el servidor está abajo a la derecha.
static void cargarSuelo(uint16_t largoX, uint16_t largoY, std::map<Tile, std::shared_ptr<Superficie>>& tilesASuelo, Json& pistaJson) {
    for (uint16_t i = 0; i < largoX; ++i) {
        for (uint16_t j = 0; j < largoY; ++j) {
            int uuidTerreno = pistaJson["capas"]["terreno"][std::to_string(i)][std::to_string(j)].get<int>();
            int uuidPista = pistaJson["capas"]["pista"][std::to_string(i)][std::to_string(j)].get<int>();
            // Hay pista
            if (uuidPista != CONFIG_SERVIDOR.tileVacio()) {
                tilesASuelo[Tile(i, largoY - j)] = SuperficieFactory::instanciar(uuidPista);
            } else {
                tilesASuelo[Tile(i, largoY - j)] = SuperficieFactory::instanciar(uuidTerreno);
            }
        }
    }
}

static void cargarPosicionesIniciales(uint16_t largoX, uint16_t largoY, std::stack<Tile>& tiles_, Json& pistaJson) {
    int cupos = pistaJson["posicionesIniciales"]["cantidad"].get<int>();
    for (int i = 0; i < cupos; ++i) {
        int x = pistaJson["posicionesIniciales"][std::to_string(i)]["x"].get<int>();
        int y = largoY - pistaJson["posicionesIniciales"][std::to_string(i)]["y"].get<int>();
        tiles_.emplace(Tile(x, y));
    }
}

/*
static void cargarModificadores(uint16_t largoX, uint16_t largoY, std::map<Tile, std::shared_ptr<Superficie>>& tilesASuperficie, Json& pistaJson) {
    for (uint16_t i = 0; i < largoX; ++i) {
        for (uint16_t j = 0; j < largoY; ++j) {
            //TODO: Acá se usa el superficieFactory
            //TODO: Superficies son barro y aceite
            //tilesASuperficie[Tile(i, largoY - j)] = pistaJson["capas"]["superficies"][std::to_string(i)][std::to_string(j)];
        }
    }
}
*/