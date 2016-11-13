#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "Ship.h"
#include "Effect.h"

class Player : public Ship
{
public:
  Player();

  void Update();
  void Draw();
  void OnHit();

private:
  void Shoot();
  bool OutOfBounds(const Vector2& position);

private:
  std::pair<Effect*, Effect*> _exhaust;
};

#endif