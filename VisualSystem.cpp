#include "VisualSystem.h"

VisualSystem::VisualSystem(SDL_Renderer* ren) : System(),
m_components(ObjectPooler<VisualComponent>(100)),
m_textureManager(ren),
r_renderer(ren)
{
}

VisualSystem::~VisualSystem()
{
}

void VisualSystem::Update(Scene & s)
{
	SDL_RenderClear(r_renderer);
	for (int i = 0; i < m_components.ActiveTotal(); i++) {
		
		SDL_RenderCopy(r_renderer, m_textureManager.GetTexture(m_components[i].m_textureID), NULL, NULL);
	}

	SDL_RenderPresent(r_renderer);
}

int VisualSystem::AddComponent(Entity* e, Component *c)
{
	int i = m_components.Create();
	if (c != nullptr) {
		m_components[i] = *((VisualComponent*)c);
		delete c;
	}
	m_components[i].m_entity = e;

	return 0;
}

void VisualSystem::LoadTexture(const std::string& file, const std::string& id)
{
	m_textureManager.LoadTexture(file, id);
}
