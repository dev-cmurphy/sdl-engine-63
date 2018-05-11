#pragma once
#include "ObjectPooler.h"

class Entity;
class Scene;

class System {

public:
  System();
  ~System();
  
  virtual int AddComponent(const Entity&) = 0;
  virtual void Update(Scene&) = 0;

protected:

}
