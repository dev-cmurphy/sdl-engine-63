#include "Entity.h"

Entity::Entity()
{
	m_components = std::unordered_map<System*, int>();
}

Entity::~Entity()
{

}

void Entity::AddComponent(System * sys, Component* c)
{

	m_components[sys] = sys->AddComponent(this, c);
}
