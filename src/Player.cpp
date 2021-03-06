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

  std::vector<std::string> _exhaustImgNames;
  _exhaustImgNames.push_back("Assets/Effects/rsz_fire11.png");
  _exhaustImgNames.push_back("Assets/Effects/rsz_fire12.png");
  _exhaustImgNames.push_back("Assets/Effects/rsz_fire13.png");
  _exhaustImgNames.push_back("Assets/Effects/rsz_fire12.png");

  int interval = 100; // interval (ms) in which the images will be changed

  _exhaust.first = new Effect(
    _exhaustImgNames, /* images that will be looped */
    interval,
    Vector2(_position.GetX() + 10, _position.GetY() - _imgHeight + 12));
  _exhaust.second = new Effect(
    _exhaustImgNames,
    interval,
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

  // Movement
  if (Input::GetKey('w')) {
    if (canBeAddedSafely(Vector2::Up)) {
      velocity += Vector2::Up;
    }
  }
  if (Input::GetKey('d')) {
    if (canBeAddedSafely(Vector2::Right)) {
      velocity += Vector2::Right;
    }
  }
  if (Input::GetKey('s')) {
    if (canBeAddedSafely(Vector2::Down)) {
      velocity += Vector2::Down;
    }
  }
  if (Input::GetKey('a')) {
    if (canBeAddedSafely(Vector2::Left)) {
      velocity += Vector2::Left;
    }
  }

  // Actions
  if (Input::GetKey('l')) {
    Shoot();
  }

  if (velocity == Vector2::Zero) {
    return;
  }

  velocity.Normalize();

  addVectorSafely(velocity);

  _exhaust.first->SetPosition(_exhaust.first->GetPosition() + getAddedVelocity(velocity));
  _exhaust.second->SetPosition(_exhaust.second->GetPosition() + getAddedVelocity(velocity));
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

Vector2 Player::getAddedVelocity(const Vector2& velocity)
{
  return velocity * _speed * GameTime::GetDeltaTime();
}

bool Player::canBeAddedSafely(Vector2 vector)
{
  return !OutOfBounds(_position + getAddedVelocity(vector.Normalized()));
}

void Player::addVectorSafely(Vector2 vector)
{
  if (canBeAddedSafely(vector)) {
      _position += getAddedVelocity(vector.Normalized());
  }
}

void Player::OnHit()
{
  if (_removed) {
    return;
  }

  _removed = true;
}
