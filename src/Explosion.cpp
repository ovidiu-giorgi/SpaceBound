#include "Explosion.h"
#include "Resources.h"
#include "Screen.h"
#include "GameTime.h"

#define DURATION 1000

Explosion::Explosion()
{
  _image = Resources::LoadImage("Assets/spaceshooter/PNG/Lasers/laserBlue08.png");
  _spawnedMS = GameTime::GetTimeMS();
}

Explosion::~Explosion()
{
  delete _image;
}

Explosion::Explosion(const Vector2& position) :
  Explosion()
{
  _position = position;
}

Explosion::Explosion(const Vector2& position, float speed) :
  Explosion(position)
{
  _speed = speed;
}

void Explosion::Update()
{
  if (GameTime::GetTimeMS() - _spawnedMS >= DURATION) {
    _removed = true;
  } else {
    Vector2 velocity = Vector2::Down;
    _position += velocity * _speed * GameTime::GetDeltaTime();
  }
}

void Explosion::Draw()
{
  Screen::Draw(_image, _position);
}