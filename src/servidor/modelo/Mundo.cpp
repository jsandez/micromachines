#include "includes/servidor/modelo/Mundo.h"

#include <string>
#include <fstream>
#include <iostream>
#include <map>

#include "includes/servidor/utils/ConfigServidor.h"
#include "includes/3rd-party/jsoncpp/json.hpp"
#include "includes/common/Tile.h"

//Forward declaration
static void cargarSuelo(int largoX, int largoY, std::map<Tile,int>& tilesASuelo, Json& pistaJson);

Mundo::Mundo(uint16_t uuidPista) {
    //TODO: Aca se carga la pista json
    //TODO: Es mejor cargar todas las pistas al inicio y luego hacer un get() para no tener que ir
    // siempre a disco.
    std::string rutaPista = CONFIG_SERVIDOR.rutaPistas() + std::to_string(uuidPista) + ".json";
    std::ifstream archivoPista(rutaPista);
    Json pistaJson;
    archivoPista >> pistaJson;
    int x = pistaJson["dimensiones"]["x"].get<int>();
    int y = pistaJson["dimensiones"]["y"].get<int>();
    std::map<Tile, int> tilesASuelo;
    cargarSuelo(x, y, tilesASuelo, pistaJson);

}

static void cargarSuelo(int largoX, int largoY, std::map<Tile,int>& tilesASuelo, Json& pistaJson) {
    for (int i = 0; i < largoX; ++i) {
        for (int j = 0; j < largoY; ++j) {
            tilesASuelo[Tile(i, largoY - j)] = pistaJson["capas"]["terreno"][std::to_string(i)][std::to_string(j)];
            int idPista = pistaJson["capas"]["pista"][std::to_string(i)][std::to_string(j)];
            if (idPista != -1) {
                tilesASuelo[Tile(i, largoY - j)] = idPista;
            }
        }
    }
}

/*Terreno desaparicion 116, 131
Terreno tierra 90 ... 115, 117 ... 130*/
