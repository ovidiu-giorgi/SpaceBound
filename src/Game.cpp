#include "Game.h"

#if defined(__linux__) || defined(__APPLE__)
  #include <SDL2/SDL.h>
#elif defined(_WIN32)
  #include <SDL.h>
#endif

#include "GameTime.h"
#include "Input.h"
#include "Screen.h"
#include "GameScene.h"
#include "MenuScene.h"

#define FRAMES_PER_SECOND 1000
#define TIME_PER_FRAME (1000 / FRAMES_PER_SECOND)
#define TICKS_PER_FRAME (1.0 / FRAMES_PER_SECOND)

Game::Game() :
  _gameOver(false),
  _hasSceneQueued(false)
{
  _currentScene = new GameScene();

  GameTime::Init();
}

Game::~Game()
{

}

Game* Game::Instance()
{
  static Game instance;

  return &instance;
}

void Game::Start()
{
  while (!_gameOver)
  {
    if (_hasSceneQueued) {
      delete _currentScene;
      _currentScene = _nextScene;
      _hasSceneQueued = false;
      // GameTime::Init();
    }

    Screen::Clear();

    GameTime::UpdateFrame();
    Input::UpdateState();

    _currentScene->Update();
    _currentScene->Display();

    Screen::Render();

    if (TICKS_PER_FRAME > GameTime::GetElapsedTimeMS() - GameTime::GetTimeMS()) {
      SDL_Delay(TICKS_PER_FRAME -(GameTime::GetElapsedTimeMS() - GameTime::GetTimeMS()));
    }
  }

  delete _currentScene;
}

void Game::Restart()
{
  SwitchScene(new GameScene());
}

void Game::End()
{
  _gameOver = true;
}

void Game::SwitchScene(Scene* scene)
{
  _nextScene = scene;
  _hasSceneQueued = true;
}