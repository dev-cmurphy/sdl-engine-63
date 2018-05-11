#include <iostream>
#include "ObjectPooler.h"
#include "TextureManager.h"

using namespace std;


int main(int argc, char* argv[]) {

	SDL_Window* win;
	SDL_Renderer* ren;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return -1;

	win = SDL_CreateWindow("SDL!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	SDL_Event e;
	TextureManager texManager(ren);
	SDL_Texture * tex = texManager.LoadTexture("emoji.png", "emoji");

	ObjectPooler<int> intPool(10);
	intPool[0] = 3;
	intPool[1] = -23;
	intPool[3] = -4;
	intPool.Activate(0);
	intPool.Activate(3);
	intPool.Deactivate(0);

	for (int i = 0; i < intPool.ActiveTotal(); i++) {
		cout << intPool[i] << "\n";
	}

	while (1) {
		while (SDL_PollEvent(&e) != 0) {

			if (e.type == SDL_QUIT)
				return 0;
		}

		SDL_RenderClear(ren);

		SDL_RenderCopy(ren, texManager.GetTexture("emoji"), NULL, NULL);

		SDL_RenderPresent(ren);
	}

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;
}