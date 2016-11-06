#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "SceneObject.h"

class Scene
{
public:
  Scene();
  virtual ~Scene();

  virtual void Update() = 0;
  virtual void Display() = 0;
  virtual void Clear() = 0;

protected:
  std::vector<SceneObject*> _sceneObjects;
};

#endif