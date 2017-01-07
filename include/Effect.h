#ifndef EFFECT_H
#define EFFECT_H

#include "SceneObject.h"
#include "Vector2.h"
#include "Image.h"

#include <vector>

class Effect : public SceneObject
{
public:
  Effect();
  virtual ~Effect();
  Effect(const std::vector<std::string>& imgNames, uint32_t interval, const Vector2& position);
  Effect(const Effect& other);
  Effect& operator=(const Effect& other);

  virtual void Update();
  virtual void Draw();

  Vector2 GetPosition();
  void SetPosition(const Vector2& position);

private:
  int GetNext();

private:
  std::vector<Image*> _images;
  int _size;
  int _index;
  Vector2 _position;
  uint32_t _interval;
  uint32_t _lastTimeMS;
};

#endif
