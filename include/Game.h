#ifndef GAME_H
#define GAME_H

#include "Scene.h"

class Game
{
public:
  Scene* _currentScene;

public:
  static Game* Instance();

  void Start();
  void End();

  void SwitchScene(Scene* scene);

private:
  Game();
  ~Game();
  Game(const Game& other);
  Game& operator=(const Game& other);

private:
  bool _gameOver;
  bool _switchedScene;
};

#endif