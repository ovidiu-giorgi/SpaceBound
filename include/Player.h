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
  Vector2 getAddedVelocity(const Vector2& velocity);
  bool canBeAddedSafely(Vector2 vector);
  void addVectorSafely(Vector2 vector);

private:
  std::pair<Effect*, Effect*> _exhaust;
};

#endif
