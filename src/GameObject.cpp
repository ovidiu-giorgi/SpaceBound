#include "GameObject.h"

GameObject::GameObject()
{
  
}

GameObject::~GameObject()
{
  if (_image != NULL) {
    delete _image;

    // std::cout << "~GameObject\n";
  }
}

GameObject::GameObject(const GameObject& other)
{
  _position = other._position;
  _image = other._image;
  _imgHeight = other._imgHeight;
  _imgWidth = other._imgWidth;
  _removed = other._removed;
}

GameObject& GameObject::operator=(const GameObject& other)
{
  _position = other._position;
  _image = other._image;
  _imgHeight = other._imgHeight;
  _imgWidth = other._imgWidth;
  _removed = other._removed;

  return *this;
}

bool GameObject::Collide(GameObject* other)
{
  if (IsRemoved() || other->IsRemoved()) {
    return false;
  }

  int x = _position.GetX();
  int y = _position.GetY();
  int height = GetImageHeight();
  int width = GetImageWidth();

  int other_x = other->GetPosition().GetX();
  int other_y = other->GetPosition().GetY();
  int other_height = other->GetImageHeight();
  int other_width = other->GetImageWidth();

  return (x < other_x + other_width &&
          x + width > other_x && 
          y > other_y - other_height &&
          y - height < other_y);
}

Vector2 GameObject::GetPosition() const
{
  return _position;
}

Image* GameObject::GetImage() const
{
  return _image;
}

int GameObject::GetImageHeight() const
{
  return _imgHeight; 
}

int GameObject::GetImageWidth() const
{
  return _imgWidth; 
}