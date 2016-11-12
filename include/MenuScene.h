#ifndef MENUSCENE_H
#define MENUSCENE_H

#include "Scene.h"

class MenuScene : public Scene
{
public:
  MenuScene();
  ~MenuScene();

  void Update();
  void Display();
  void Clear();
};

#endif