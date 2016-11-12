#include "MenuScene.h"
#include "GameScene.h"
#include "Background.h"
#include "Game.h"
#include "Input.h"

MenuScene::MenuScene()
{
  
}

MenuScene::~MenuScene()
{
  Clear();
}

void MenuScene::Update()
{ 
  // Update scene objects
  for (std::vector<SceneObject*>::iterator i = _sceneObjects.begin(); i != _sceneObjects.end(); ) {
    if ((*i)->IsRemoved()) {
      delete *i;
      i = _sceneObjects.erase(i);
    } else {
     (*i)->Update();
      i++;
    }
  }

  if (Input::GetKeyDown('r')) {
    Game::Instance()->Restart();
  }
  if (Input::GetKeyDown(27)) {
    Game::Instance()->End();
  }
}

void MenuScene::Display()
{
  for (auto it : _sceneObjects) {
    it->Draw();
  }
}

void MenuScene::Clear()
{
  for (auto it : _sceneObjects) {
    delete it;
  }
}