#include <SDL2/SDL.h>
#include <iostream>
#include <exception>
#include "SdlWindow.h"
#include "SdlTexture.h"

int main(int argc, char** argv){
  try {
    SdlWindow window(1920, 1080);
    window.fill();
    // Usar factory
    SdlTexture im_corner("Road_01_Tile_01.png", window);
    SdlTexture im_road("Road_01_Tile_03.png", window);

    int wh = 270;
    Area srcArea_road(0, 0, 512, 688);
    Area srcArea_corner(0, 0, 691, 691);

    Area destArea_corner_upper_left(0, 0, wh, wh);
    Area destArea_road_upper(wh - 25, 0, wh, wh);
    Area destArea_road_upper_2((wh*2) -50, 0, wh, wh);
    Area destArea_road_upper_3((wh*3) -75, 0, wh, wh);
    Area destArea_road_upper_4((wh*4) -100, 0, wh, wh);
    Area destArea_road_upper_5((wh*5) -125, 0, wh, wh);
    Area destArea_corner_upper_right((wh*6) -150, 0, wh, wh);
    Area destArea_road_upper_6((wh*6) -150, wh-25, wh, wh);
    Area destArea_road_upper_7((wh*6) -150, (wh*2)-50, wh, wh);
    Area destArea_corner_lower_right((wh*6) -150, (wh*3)-75, wh, wh);


    im_road.render(srcArea_road,destArea_road_upper);
    im_road.render(srcArea_road,destArea_road_upper_2);
    im_road.render(srcArea_road,destArea_road_upper_3);
    im_road.render(srcArea_road,destArea_road_upper_4);
    im_road.render(srcArea_road,destArea_road_upper_5);
    im_road.render(srcArea_road,destArea_road_upper_6,(double) -90,SDL_FLIP_NONE);
    im_road.render(srcArea_road,destArea_road_upper_7,(double) -90, SDL_FLIP_NONE );
    im_corner.render(srcArea_corner,destArea_corner_upper_left,(double)90,SDL_FLIP_NONE);
    im_corner.render(srcArea_corner, destArea_corner_upper_right, (double)180, SDL_FLIP_NONE);
    im_corner.render(srcArea_corner, destArea_corner_lower_right, (double) -90, SDL_FLIP_NONE);
    window.render();
    SDL_Delay(3000);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}