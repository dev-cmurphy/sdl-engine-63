#include "TextureManager.h"



TextureManager::TextureManager(SDL_Renderer* renderer) :
	r_renderer(renderer)
{
}


TextureManager::~TextureManager()
{
}


SDL_Texture * TextureManager::LoadTexture(const std::string& str, const std::string& id) {

	SDL_Texture * tex = nullptr;

	SDL_Surface* surf = IMG_Load(str.c_str());

	tex = SDL_CreateTextureFromSurface(r_renderer, surf);

	m_textures[id] = tex;

	SDL_FreeSurface(surf);
	return tex;
}

SDL_Texture * TextureManager::GetTexture(const std::string& id)
{
	if (m_textures.find(id) != m_textures.end())
		return m_textures[id];

	return nullptr;
}

