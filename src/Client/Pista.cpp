#include "Pista.h"

Pista::Pista(int width, int height) : width(width), height(height) {}

void Pista::dibujar(SdlWindow &sdl_window) {
  SdlTexture im_corner("Road_01_Tile_01.png", sdl_window);
  SdlTexture im_road("Road_01_Tile_03.png", sdl_window);

  Area srcArea_road(0, 0, 512, 688);
  Area srcArea_corner(0, 0, 691, 691);

  Area destArea_corner_upper_left(0, 0, this->width, this->height);
  Area destArea_road_upper(this->width - 25, 0, this->width, this->height);
  Area destArea_road_upper_2((this->width * 2) - 50, 0, this->width, this->height);
  Area destArea_road_upper_3((this->width * 3) - 75, 0, this->width, this->height);
  Area destArea_road_upper_4((this->width * 4) - 100, 0, this->width, this->height);
  Area destArea_road_upper_5((this->width * 5) - 125, 0, this->width, this->height);
  Area destArea_corner_upper_right((this->width * 6) - 150, 0, this->width, this->height);
  Area destArea_road_upper_6((this->width * 6) - 150, this->height - 25, this->width, this->height);
  Area destArea_road_upper_7((this->width * 6) - 150, (this->height * 2) - 50, this->width, this->height);
  Area destArea_corner_lower_right((this->width * 6) - 150, (this->height * 3) - 75, this->width, this->height);

  im_road.render(srcArea_road, destArea_road_upper);
  im_road.render(srcArea_road, destArea_road_upper_2);
  im_road.render(srcArea_road, destArea_road_upper_3);
  im_road.render(srcArea_road, destArea_road_upper_4);
  im_road.render(srcArea_road, destArea_road_upper_5);
  im_road.render(srcArea_road, destArea_road_upper_6, (double) -90, SDL_FLIP_NONE);
  im_road.render(srcArea_road, destArea_road_upper_7, (double) -90, SDL_FLIP_NONE);
  im_corner.render(srcArea_corner, destArea_corner_upper_left, (double) 90, SDL_FLIP_NONE);
  im_corner.render(srcArea_corner, destArea_corner_upper_right, (double) 180, SDL_FLIP_NONE);
  im_corner.render(srcArea_corner, destArea_corner_lower_right, (double) -90, SDL_FLIP_NONE);
}