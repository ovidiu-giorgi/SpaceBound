#include "GameScene.h"
#include "ScrollingBG.h"
#include "Game.h"
#include "Player.h"

// delete this
#include "Asteroid.h"
#include "Screen.h"

#include <iostream>

GameScene::GameScene()
{
  // Add scene objects
  _sceneObjects.push_back(new ScrollingBG());

  // Add game objects
  _player = new Player();
  _gameObjects.push_back(_player);

  // Add spawner
  _waveSpawner = new WaveSpawner();
}

GameScene::~GameScene()
{
  Clear();
}

void GameScene::Update()
{
  // Spawn enemies
  std::vector<GameObject*> enemies = _waveSpawner->GetWave(_gameObjects);
  for (auto it : enemies) {
    _gameObjects.push_back(it);
  }

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

  // Update game objects
  for (std::vector<GameObject*>::iterator i = _gameObjects.begin(); i != _gameObjects.end(); ) {
    if ((*i)->IsRemoved()) {
      delete *i;
      i = _gameObjects.erase(i);
    } else {
     (*i)->Update();
      i++;
    }
  }

  // Check for collisions
  // std::cout << "_gameObjects: " << _gameObjects.size() << '\n';
  for (int i = 0; i < _gameObjects.size(); i++) {
    for (int j = i + 1; j < _gameObjects.size(); ++j) {
      if (_gameObjects[i]->Collide(_gameObjects[j]) ||
          _gameObjects[j]->Collide(_gameObjects[i])) {
        std::cout << "Collision\n";
        _gameObjects[i]->OnHit();
        _gameObjects[j]->OnHit();
      }
    }
  }
}

void GameScene::Display()
{
  for (auto it : _sceneObjects) {
    it->Draw();
  }

  for (auto it : _gameObjects) {
    it->Draw();
  }
}

void GameScene::Clear()
{
  for (auto it : _sceneObjects) {
    delete it;
  }

  for (auto it : _gameObjects) {
    delete it;
  }
}