#pragma once
#include "System.h"
#include "VisualComponent.h"
#include "TextureManager.h"


class VisualSystem : public System {
public:
	
	VisualSystem(SDL_Renderer*);
	~VisualSystem();
  
	virtual void Update(Scene&);
	int AddComponent(Entity*, Component *c);

	void LoadTexture(const std::string& file, const std::string& id);

protected:
	ObjectPooler<VisualComponent> m_components;
private:
	TextureManager m_textureManager;
	SDL_Renderer* r_renderer;
};
