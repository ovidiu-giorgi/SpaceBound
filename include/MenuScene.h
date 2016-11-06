#ifndef MENUSCENE_H
#define MENUSCENE_H

#include "Scene.h"

class MenuScene : public Scene
{
public:
  static MenuScene* Instance();

  void Update();
  void Display();
  void Clear();

private:
  MenuScene();
  ~MenuScene();
  MenuScene(const MenuScene& other);
  MenuScene& operator=(const MenuScene& other);
};

#endif