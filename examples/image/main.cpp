#include <SDL.h>
#include <SDL_image.h>
#include <sdl2xx.hpp>
#include <sdl2xx/image.hpp>
#include <iostream>
#include <cstdlib>

namespace Image = SDL::Image;

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
		std::cerr << SDL_GetError() << std::endl;
		return 1;
	}
	std::atexit([]() {
		SDL_Quit();
	});

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		std::cerr << IMG_GetError() << std::endl;
		return 1;
	}
	std::atexit([]() {
		IMG_Quit();
	});

	auto w = SDL::CreateWindow("image_example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	auto r = SDL::CreateRenderer(w.get(), -1, 0);
	auto t = Image::LoadTexture(r.get(), "blue_torus.png");

	for (;;) {
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				break;
			}
		}

		SDL_RenderClear(r.get());
		SDL_RenderCopy(r.get(), t.get(), NULL, NULL);
		SDL_RenderPresent(r.get());
	}
}
