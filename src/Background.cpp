#include "Background.h"
#include "Resources.h"
#include "Screen.h"

Background::Background()
{
  _position = Vector2(0, Screen::GetHeight());
  _image = Resources::LoadImage("Assets/Backgrounds/bg_black.jpg");
}

Background::~Background()
{
  std::cout << "~Background\n";
  delete _image;
}

Background::Background(const Vector2& position)
{
  _position = position;
  _image = Resources::LoadImage("Assets/Backgrounds/bg_black.jpg");
}

Background::Background(const std::string& imgName)
{
  _position = Vector2(0, Screen::GetHeight());
  _image = Resources::LoadImage(imgName);
}

Background::Background(const Vector2& position, const std::string& imgName)
{
  _position = position;
  _image = Resources::LoadImage("Assets/" + imgName);
}

void Background::Update()
{

}

void Background::Draw()
{
  Screen::Draw(_image, _position);
}

Vector2 Background::GetPosition() const
{
  return _position;
}

void Background::SetPosition(const Vector2& position)
{
  _position = position;
}