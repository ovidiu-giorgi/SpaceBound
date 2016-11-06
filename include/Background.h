#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "SceneObject.h"

#include "Vector2.h"
#include "Image.h"

class Background : public SceneObject
{   
public:
  Background();
  ~Background();
  Background(const Vector2& position);
  Background(const std::string& imgName);
  Background(const Vector2& position, const std::string& imgName);
  
  void Update();
  void Draw();

  Vector2 GetPosition() const;
  void SetPosition(const Vector2& position);

private:
  Vector2 _position;
  Image* _image;
};

#endif