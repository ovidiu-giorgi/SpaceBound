#include "Effect.h"
#include "Screen.h"
#include "Resources.h"
#include "GameTime.h"

Effect::Effect()
{

}

Effect::Effect(const std::vector<std::string>& imgNames, uint32_t interval, const Vector2& position)
{
  // Load images
  _index = -1;
  _size = imgNames.size();
  for (int i = 0; i < _size; i++) {
    _images.push_back(Resources::LoadImage(imgNames[i]));
  }
  _interval = interval;
  _position = position;
}

Effect::~Effect()
{
  for (auto it : _images) {
    delete it;
  }
}

Effect::Effect(const Effect& other)
{
  _size = other._size;
  _images = other._images;
  _index = other._index;
  _position = other._position;
  _interval = other._interval;
  _removed = other._removed;
}

Effect& Effect::operator=(const Effect& other)
{
  _size = other._size;
  _images = other._images;
  _index = other._index;
  _position = other._position;
  _interval = other._interval;
  _removed = other._removed;

  return *this;
}

Vector2 Effect::GetPosition()
{
  return _position;
}

void Effect::SetPosition(const Vector2& position)
{
  _position = position;
}

void Effect::Update()
{
  if (GameTime::GetTimeMS() - _lastTimeMS >= _interval) {
    _index = GetNext();
    _lastTimeMS = GameTime::GetTimeMS();
  }
}

void Effect::Draw()
{
  int cnt = 0;
  for (auto it : _images) {
    if (cnt == _index) {
      Screen::Draw(it, _position);
      break;
    }
    cnt++;
  }
}

int Effect::GetNext()
{
  if (_index + 1 == _size) {
    _index = -1;
  }

  _index++;

  return _index;
}
