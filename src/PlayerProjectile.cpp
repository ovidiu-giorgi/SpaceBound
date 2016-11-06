#include "PlayerProjectile.h"

#include "Input.h"
#include "GameTime.h"

#include <cstdlib>

#define IMG_HEIGHT 7
#define IMG_WIDTH 42
#define SPEED 600

// Default constructor
PlayerProjectile::PlayerProjectile()
{
  _position = Vector2(rand() % Screen::GetWidth(), rand() % Screen::GetHeight());
  _image = Resources::LoadImage("Assets/Lasers/laser_blue.png");
  _imgHeight = IMG_WIDTH;
  _imgWidth = IMG_WIDTH;
  _speed = SPEED;
}

// Spawns a projectile relative to a given position
PlayerProjectile::PlayerProjectile(const Vector2& pos)
{
  _position = Vector2(pos.GetX() + IMG_WIDTH - 8, pos.GetY() + 40);
  _image = Resources::LoadImage("Assets/Lasers/laser_blue.png");
  _imgHeight = IMG_WIDTH;
  _imgWidth = IMG_WIDTH;
  _speed = SPEED;
  // std::cout << "PlayerProjectile: " << _position.GetX() << ' ' << _position.GetY() << '\n';
}

// Spawns a projectile relative to a given position and with a given speed
PlayerProjectile::PlayerProjectile(const Vector2& pos, int speed)
{
  _position = Vector2(pos.GetX() + (IMG_WIDTH + 20) / 2, pos.GetY() + 500);
  _image = Resources::LoadImage("Assets/Lasers/laser_blue.png");
  _imgHeight = IMG_WIDTH;
  _imgWidth = IMG_WIDTH;
  _speed = SPEED + speed;
}

void PlayerProjectile::Update()
{
  Vector2 velocity = Vector2::Up;

  velocity.Normalize();

  _position += velocity * _speed * GameTime::GetDeltaTime();

  CheckBounds();
}

void PlayerProjectile::Draw()
{
  Screen::Draw(_image, _position);
}

void PlayerProjectile::OnHit()
{
  if (_removed) {
    return;
  }

  // std::cout << "PlayerProjectile OnHit\n";

  _removed = true;
}

void PlayerProjectile::CheckBounds()
{
  if (_removed) return;
  _removed = (_position.GetY() - IMG_HEIGHT) > Screen::GetHeight();
}