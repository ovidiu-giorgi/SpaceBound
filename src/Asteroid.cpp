#include "Asteroid.h"
#include "Input.h"
#include "GameTime.h"
#include "GameScene.h"
#include "Explosion.h"

#include <cstdlib>

#define SPEED 450

struct Pair {
  int width;
  int height;

  Pair()
  {
    // Nothing
  }

  Pair(std::pair<int, int> p)
  {
    width = p.first;
    height = p.second;
  }
};

Asteroid::Asteroid() :
  _speed(SPEED)
{
  // Set all the possible sizes of asteroids
  Pair sizes[7];
  sizes[1] = std::make_pair(51, 42);
  sizes[2] = std::make_pair(60, 49);
  sizes[3] = std::make_pair(45, 41);
  sizes[4] = std::make_pair(49, 48);
  sizes[5] = std::make_pair(43, 43);
  sizes[6] = std::make_pair(45, 40);

  // Pick a random size 
  int rnd_size = rand() % 6 + 1;

  // Pick a random color
  std::string rnd_color = rand() % 2 == 0 ? "brown" : "grey";

  // Construct the filename for the asteroid image
  std::string filename = "Assets/Asteroids/" + rnd_color + std::to_string(rnd_size) + ".png";

  // Load the image
  // _image = Resources::LoadImage("Assets/Asteroids/brown6.png");
  // _imgWidth = 45;
  // _imgHeight = 40;
  _image = Resources::LoadImage(filename);
  _imgWidth = sizes[rnd_size].height;
  _imgHeight = sizes[rnd_size].width;
  _position = Vector2(
    rand() % (Screen::GetWidth() - _imgWidth),
    Screen::GetHeight() + _imgHeight + rand() % 500);
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