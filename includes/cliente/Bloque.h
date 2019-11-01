#ifndef _BLOQUE_H_
#define _BLOQUE_H_

class Bloque {
 private:
  const int x, y;
 public:
  Bloque(int x,int y);
  int getX() const;
  int getY() const;
};
#endif
