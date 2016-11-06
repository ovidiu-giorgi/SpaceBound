#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"
#include "GameObject.h"
#include "WaveSpawner.h"

class GameScene : public Scene
{
public:
  GameScene();
  ~GameScene();

  void Update();
  void Display();
  void Clear();

private:
  std::vector<GameObject*> _gameObjects;
  GameObject* _player;
  WaveSpawner* _waveSpawner;
};

#endif