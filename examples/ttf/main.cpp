#include <SDL.h>
#include <SDL_ttf.h>
#include <sdl2xx.hpp>
#include <sdl2xx/ttf.hpp>
#include <iostream>
#include <cstdlib>

namespace TTF = SDL::TTF;

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
		std::cerr << SDL_GetError() << std::endl;
		return 1;
	}
	std::atexit([]() {
		SDL_Quit();
	});

	if (TTF_Init() == -1) {
		std::cerr << TTF_GetError() << std::endl;
		return 1;
	}
	std::atexit([]() {
		TTF_Quit();
	});

	auto w = SDL::CreateWindow("ttf_example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	auto r = SDL::CreateRenderer(w.get(), -1, 0);
	auto f = TTF::OpenFont("DejaVuSans.ttf", 72);
	auto s = TTF::RenderTextShaded(f.get(), u8"SDL2XX ♥", SDL_Color {.r = 255, .g = 255, .b = 255}, SDL_Color {.r = 0, .g = 0, .b = 0});
	auto t = SDL::CreateTexture(r.get(), s.get());

	for (;;) {
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				break;
			}
		}

		SDL_RenderClear(r.get());
		SDL_Rect dstrect {.x = 320 - s->w/2, .y = 240 - s->h/2, .w = s->w, .h = s->h};
		SDL_RenderCopy(r.get(), t.get(), NULL, &dstrect);
		SDL_RenderPresent(r.get());
	}

}
