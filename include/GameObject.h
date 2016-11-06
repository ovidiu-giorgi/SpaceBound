#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SceneObject.h"

#include "Vector2.h"
#include "Image.h"
#include "Screen.h"
#include "Resources.h"

class GameObject : public SceneObject
{
public:
  GameObject();
  virtual ~GameObject();
  GameObject(const GameObject& other);
  GameObject& operator=(const GameObject& other);

  virtual bool Collide(GameObject* other);
  virtual void OnHit() = 0;

  Vector2 GetPosition() const;
  Image* GetImage() const;
  int GetImageHeight() const;
  int GetImageWidth() const;

protected:
  Vector2 _position;
  Image* _image;
  int _imgHeight;
  int _imgWidth;
};

#endif