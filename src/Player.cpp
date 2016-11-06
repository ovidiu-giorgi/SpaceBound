#include "Player.h"

#include "GameScene.h"

#include "Screen.h"
#include "Game.h"
#include "GameTime.h"
#include "Input.h"

#include <cstdlib>

#define IMG_WIDTH 74
#define IMG_HEIGHT 56
#define SPEED 320
#define INTERVAL 150

Player::Player()
{
  _position = Vector2((Screen::GetWidth() - IMG_WIDTH) / 2, IMG_HEIGHT);
  // _position = Vector2(rand() % Screen::GetWidth(), rand() % Screen::GetHeight());
  _image = Resources::LoadImage("Assets/Ships/player_ship_blue.png");
  _imgWidth = IMG_WIDTH;
  _imgHeight = IMG_HEIGHT;
  _speed = SPEED;
}

Player::Player(int x, int y)
{
  _position = Vector2(x, y);
  _image = Resources::LoadImage("Assets/Ships/player_ship_blue.png");
  _imgWidth = IMG_WIDTH;
  _imgHeight = IMG_HEIGHT;
  _speed = SPEED;
}

void Player::Update()
{
  // Update bullets
  for (std::vector<Projectile*>::iterator i = _bullets.begin(); i != _bullets.end(); ) {
    if ((*i)->IsRemoved()) {
      delete *i;
      i = _bullets.erase(i);
    } else {
     (*i)->Update();
      i++;
    }
  }

  // Update player ship
  Vector2 velocity = Vector2::Zero;

  if (Input::GetKey('w')) {
    velocity += Vector2::Up;
  }
  if (Input::GetKey('d')) {
    velocity += Vector2::Right;
  }
  if (Input::GetKey('s')) {
    velocity += Vector2::Down;
  }
  if (Input::GetKey('a')) {
    velocity += Vector2::Left;
  }
  if (Input::GetKey('l')) {
    Shoot();
  }

  if (velocity == Vector2::Zero) {
    return;
  }

  velocity.Normalize();

  Vector2 position = _position + velocity * _speed * GameTime::GetDeltaTime();

  if (!OutOfBounds(position)) {
    _position = position;
  }
}

void Player::Shoot()
{
  if (GameTime::GetTimeMS() - _lastTimeMS >= INTERVAL) {
    // GameScene::Instance()->AddGameObject(new PlayerProjectile(_position));
    _bullets.push_back(new PlayerProjectile(_position));
    _lastTimeMS = GameTime::GetTimeMS();
  }
}

void Player::Draw()
{
  // Update bullets
  for (auto it : _bullets) {
    it->Draw();
  }

  // Update player ship
  Screen::Draw(_image, _position);
}

bool Player::OutOfBounds(const Vector2& position)
{
  int x = position.GetX();
  int y = position.GetY();

  if (x < 0 || y > Screen::GetHeight()) return true;
  if (x + IMG_WIDTH > Screen::GetWidth() || y - IMG_HEIGHT < 0) return true;

  return false;
}

void Player::OnHit()
{
  if (_removed) {
    return;
  }

  _removed = true;
}