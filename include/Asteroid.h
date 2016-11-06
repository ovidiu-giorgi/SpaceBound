#ifndef ASTEROID_H
#define ASTEROID_H

#include "GameObject.h"

class Asteroid : public GameObject
{
public:
  Asteroid();
  ~Asteroid();
  
  void Update();
  void Draw();
  void OnHit();

private:
  void CheckBounds();

private:
  float _speed;
};

#endif