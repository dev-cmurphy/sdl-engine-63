#pragma once
#include "ObjectPooler.h"

class Entity;
class Scene;
class Component;

class System {
	friend class Entity;
public:
	System() {};
	~System() {};
  
	virtual void Update(Scene&) = 0;

protected:

	virtual int AddComponent(Entity*, Component*) = 0;
};
