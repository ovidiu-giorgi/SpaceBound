#include "SceneObject.h"

SceneObject::SceneObject() :
  _removed(false)
{

}

SceneObject::~SceneObject()
{

}

SceneObject::SceneObject(const SceneObject& other) :
  _removed(other._removed)
{

}

SceneObject& SceneObject::operator=(const SceneObject& other)
{
  _removed = other._removed;

  return *this;
}

bool SceneObject::IsRemoved() const
{
  return _removed;
}