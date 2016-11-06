#ifndef SCROLLINGBG_H
#define SCROLLINGBG_H

#include "SceneObject.h"

#include "Background.h"

#include <vector>

class ScrollingBG : public SceneObject
{ 
public:
  ScrollingBG();
  ~ScrollingBG();

  void Update();
  void Draw();

private:
  std::vector<Background*> _bgs;
  float _speed;
};

#endif