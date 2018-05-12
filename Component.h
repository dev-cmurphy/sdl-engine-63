#pragma once
#include "Entity.h"

class Component {
public:
	Component(Entity* e = nullptr);
	virtual ~Component();
	
	virtual void Activate() = 0;
	virtual void Deactivate() = 0;

protected:
	// data
	Entity * m_entity;
};