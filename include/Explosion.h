#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "SceneObject.h"

#include "Vector2.h"
#include "Image.h"

class Explosion : public SceneObject
{
public:
  Explosion();
  ~Explosion();
  Explosion(const Vector2& position);
  Explosion(const Vector2& position, float speed);

  void Update();
  void Draw();
  
private:
  Vector2 _position;
  Image* _image;
  float _speed;
  uint32_t _spawnedMS;
};

#endif