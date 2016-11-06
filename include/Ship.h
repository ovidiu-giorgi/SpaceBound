#ifndef SHIP_H
#define SHIP_H

#include "GameObject.h"

#include "Projectile.h"

#include <vector>

class Ship : public GameObject
{
public:
  ~Ship();
  bool Collide(GameObject* other);
  
protected:
  std::vector<Projectile*> _bullets;
  float _speed;
  uint32_t _lastTimeMS;
};

#endif