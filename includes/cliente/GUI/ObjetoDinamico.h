#ifndef _OBJETO_DINAMICO_H_
#define _OBJETO_DINAMICO_H_
#include "includes/cliente/GUI/AnimacionFactory.h"
#include "includes/cliente/GUI/Animacion.h"
#include "includes/cliente/GUI/Renderizador.h"

class ObjetoDinamico {
 private:
  int x, y, angulo, vida;
  Animacion animacion_;

 public:
  ObjetoDinamico(int uuid, Renderizador& renderizador);
  Animacion &getAnimacion();
  void mover(int x,int y, int angulo);
  void setVida(int vida);
  int getX() const;
  int getY() const;
  int getAngulo() const;
  int getVida() const;
};
#endif
