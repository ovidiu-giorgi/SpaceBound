#include "Player.h"
#include "GameScene.h"
#include "Screen.h"
#include "Game.h"
#include "GameTime.h"
#include "Input.h"
#include "PlayerProjectile.h"

#include <cstdlib>

#define IMG_WIDTH 74
#define IMG_HEIGHT 56
#define SPEED 320
#define INTERVAL 150

Player::Player()
{
  // Set position
  _position = Vector2((Screen::GetWidth() - IMG_WIDTH) / 2, IMG_HEIGHT + 30);
  // _position = Vector2(rand() % Screen::GetWidth(), rand() % Screen::GetHeight());

  // Load images
  _image = Resources::LoadImage("Assets/Ships/player_ship_blue.png");
  _imgWidth = IMG_WIDTH;
  _imgHeight = IMG_HEIGHT;

  std::string _exhaustImgNames[] = {
    "Assets/Effects/rsz_fire11.png",
    "Assets/Effects/rsz_fire12.png",
    "Assets/Effects/rsz_fire13.png",
    };

  _exhaust.first = new Effect(
    _exhaustImgNames, /* images that will be looped */
    3, /* imgNames length */
    100,  /* interval (ms) in which the images will be changed */
    Vector2(_position.GetX() + 10, _position.GetY() - _imgHeight + 12));
  _exhaust.second = new Effect(
    _exhaustImgNames,
    3,
    100,
    Vector2(_position.GetX() + _imgWidth - 17, _position.GetY() - _imgHeight + 12));

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

  // Update exhaust image
  _exhaust.first->Update();
  _exhaust.second->Update();

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
    _exhaust.first->SetPosition(_exhaust.first->GetPosition() + velocity * _speed * GameTime::GetDeltaTime());
    _exhaust.second->SetPosition(_exhaust.second->GetPosition() + velocity * _speed * GameTime::GetDeltaTime());
  }  
}

void Player::Shoot()
{
  if (GameTime::GetTimeMS() - _lastTimeMS >= INTERVAL) {
    _bullets.push_back(new PlayerProjectile(_position));
    _lastTimeMS = GameTime::GetTimeMS();
  }
}

void Player::Draw()
{
  // Draw bullets
  for (auto it : _bullets) {
    it->Draw();
  }

  // Draw ship
  Screen::Draw(_image, _position);

  // Draw exhaust
  _exhaust.first->Draw();
  _exhaust.second->Draw();
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