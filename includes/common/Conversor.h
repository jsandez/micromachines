#ifndef _CONVERSOR_H_
#define _CONVERSOR_H_

/*
 * Conversor que realiza el traspaso
 * de metros a pixeles y a bloques
 */
class Conversor {
 private:
  float pixelPorMetro;
  int pixelPorBloque;

 public:
  Conversor(float pixelPorMetro, int pixelPorBloque);
  int metroAPixel(float coord);
  float pixelAMetro(int coord);
  int metroABloque(float coord);
};
#endif
