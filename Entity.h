#pragma once
#include "System.h"
#include <unordered_map>

struct Vector2 {
	float x;
	float y;
};

class Entity {
	
public:
	Entity();
	~Entity();

	void AddComponent(System* sys, Component* c);

	Vector2 position;

protected:

	std::unordered_map<System*, int> m_components;
};