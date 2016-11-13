#include "ScrollingBG.h"
#include "Screen.h"
#include "GameTime.h"

#define SPEED 300
#define IMG_HEIGHT 1000
#define BGS_NUM 2
#define EPS 5
#define INF 2e9

ScrollingBG::ScrollingBG() :
  _speed(SPEED)
{
  for (int i = 0; i < BGS_NUM; ++i) {
    Vector2 position(0, Screen::GetHeight() + IMG_HEIGHT * i);
    _bgs.push_back(new Background(position));
  }
}

ScrollingBG::~ScrollingBG()
{
  std::cout << "~ScrollingBG\n";

  for (auto it : _bgs) {
    delete it;
  }
}

void ScrollingBG::Update()
{
  Vector2 velocity(Vector2::Down);
  velocity.Normalize();

  int maxY = -INF;
  for (auto it : _bgs) {
    it->SetPosition(it->GetPosition() + velocity * _speed * GameTime::GetDeltaTime());
    if (it->GetPosition().GetY() > maxY) {
      maxY = it->GetPosition().GetY();
    }
  }

  for (auto it : _bgs) {
    int y = it->GetPosition().GetY();
    if (y >= -EPS && y <= EPS) {
      Vector2 position(0, maxY);
      // position += _speed * GameTime::GetDeltaTime();
      Vector2 new_position(0, IMG_HEIGHT + position.GetY());
      // Vector2 new_position(0, Screen::GetHeight() + IMG_HEIGHT *(BGS_NUM - 1));
      it->SetPosition(new_position);
      break;
    }
  }
}

void ScrollingBG::Draw()
{
  for (auto it : _bgs) {
    it->Draw();
  }
}