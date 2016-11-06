#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "GameObject.h"

class Projectile : public GameObject
{
public:
  ~Projectile();

protected:
  float _speed;
};

#endif