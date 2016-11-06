#ifndef PLAYERPROJECTILE_H
#define PLAYERPROJECTILE_H

#include "Projectile.h"

class PlayerProjectile : public Projectile
{
public:
  PlayerProjectile();
  PlayerProjectile(const Vector2& player_pos);
  PlayerProjectile(const Vector2& player_pos, int speed);

  void Update();
  void Draw();
  
  void OnHit();

private:
  void CheckBounds();
};

#endif