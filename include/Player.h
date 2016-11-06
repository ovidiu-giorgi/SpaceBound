#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "Ship.h"
#include "PlayerProjectile.h"

class Player : public Ship
{
public:
  Player();
  Player(int x, int y);

  void Update();
  void Draw();
  void OnHit();

private:
  void Shoot();
  bool OutOfBounds(const Vector2& position);
};

#endif