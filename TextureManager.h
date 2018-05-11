#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <unordered_map>
#include <string>

class TextureManager
{
public:
	TextureManager(SDL_Renderer* renderer);
	~TextureManager();

	SDL_Texture* LoadTexture(const std::string& file, const std::string& id);
	SDL_Texture* GetTexture(const std::string& id);

private:
	// Nomenclature : 
	// m_ pour membre
	// r_ pour réfère à qq chose d'extérieur 

	std::unordered_map<std::string, SDL_Texture*> m_textures;
	SDL_Renderer* r_renderer;
};

