#include "Ship.h"

Ship::~Ship()
{
  std::cout << "~Ship\n";

  for (auto it : _bullets) {
    delete it;
  }
}

bool Ship::Collide(GameObject* other)
{
  if (GameObject::Collide(other)) {
    return true;
  }

  for (auto it : _bullets) {
    if (it->Collide(other)) {
      it->OnHit();
      other->OnHit();
      break;
    }
  }

  return false;
}