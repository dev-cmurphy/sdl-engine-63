#include <iostream>
#include "VisualSystem.h"
#include "Scene.h"

using namespace std;

int main(int argc, char* argv[]) {

	SDL_Window* win;
	SDL_Renderer* ren;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return -1;

	win = SDL_CreateWindow("SDL!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);

	VisualSystem vs(ren);
	Scene scene;

	vs.LoadTexture("emoji.png", "emoji");
	
	Entity entity;
	entity.AddComponent(&vs, new VisualComponent("emoji"));

	SDL_Event e;
	while (1) {
		while (SDL_PollEvent(&e) != 0) {

			if (e.type == SDL_QUIT)
				return 0;
		}

		vs.Update(scene);
	}

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;
}