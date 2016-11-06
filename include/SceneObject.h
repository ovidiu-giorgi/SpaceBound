#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "Object.h"

class SceneObject : public Object
{
public:
  SceneObject();
  virtual ~SceneObject();
  SceneObject(const SceneObject& other);
  SceneObject& operator=(const SceneObject& other);

  virtual void Update() = 0;
  virtual void Draw() = 0;

  bool IsRemoved() const;

protected:
  bool _removed;
};

#endif