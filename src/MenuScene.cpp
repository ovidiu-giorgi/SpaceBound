#include "MenuScene.h"

#include "GameScene.h"
#include "Background.h"

#include "Game.h"

MenuScene::MenuScene()
{
  // Add scene objects
  _sceneObjects.push_back(new Background("Assets/spaceshooter/rsz_game_over.jpg"));
}

MenuScene::~MenuScene()
{
  Clear();
}

MenuScene* MenuScene::Instance()
{
  static MenuScene instance;

  return &instance;
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