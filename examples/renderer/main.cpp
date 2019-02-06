#include <SDL.h>
#include <sdl2xx.hpp>
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
		std::cerr << SDL_GetError() << std::endl;
		return 1;
	}
	std::atexit([]() {
		SDL_Quit();
	});

	auto w = SDL::CreateWindow("sdl2xx", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	auto r = SDL::CreateRenderer(w.get(), -1, 0);

	for(;;) {
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				break;
			}
		}

		SDL_RenderClear(r.get());
		SDL_RenderPresent(r.get());
	}
}
