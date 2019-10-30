#include "includes/cliente/CreadorTexturas.h"

CreadorTexturas::CreadorTexturas(SdlWindow &sdl_window) :
    tierra("assets/Soil_Tile.png", sdl_window),
    pasto("assets/Grass_Tile.png", sdl_window),
    pista("assets/Road_01_Tile_03.png", sdl_window),
    curva("assets/Road_01_Tile_01.png", sdl_window),
    agua("assets/Water_Tile.png", sdl_window),
    roca("assets/Rock_01.png", sdl_window),
    bush1("assets/Bush_01.png", sdl_window),
    bush2("assets/Bush_02.png", sdl_window),
    tribuna1("assets/Decor_Building_01.png", sdl_window),
    tribuna2("assets/Decor_Building_02.png", sdl_window) {}

