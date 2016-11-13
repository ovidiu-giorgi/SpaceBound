#include "Asteroid.h"
#include "Input.h"
#include "GameTime.h"
#include "GameScene.h"
#include "Explosion.h"

#include <cstdlib>

#define IMG_WIDTH 45
#define IMG_HEIGTH 40

#define SPEED 450

Asteroid::Asteroid() :
  _speed(SPEED)
{
  // std::cout << "Asteroid created\n";

  // std::string meteorColor = rand() % 2 == 0 ? "Brown" : "Gray";
  // std::string meteorSize = rand() % 2 == 0 ? "_big" : "_med";

  _image = Resources::LoadImage("Assets/Asteroids/meteorBrown_med2.png");
  _position = Vector2(rand() % (Screen::GetWidth() - IMG_WIDTH), Screen::GetHeight() + IMG_HEIGTH + rand() % 500);
  _imgHeight = IMG_HEIGTH;
  _imgWidth = IMG_WIDTH;
}

Asteroid::~Asteroid()
{
  std::cout << "~Asteroid\n";
}

void Asteroid::Update()
{
  Vector2 velocity = Vector2::Down;

  _position += velocity * _speed * GameTime::GetDeltaTime();

  CheckBounds();
}

void Asteroid::Draw()
{
  Screen::Draw(_image, _position);
}

void Asteroid::CheckBounds()
{
  if (_removed) return;
  _removed = _position.GetY() < 0;
}

void Asteroid::OnHit()
{
  if (_removed) {
    return;
  }

  _removed = true;
}