#include <SDL.h>
#include <SDL_mixer.h>
#include <sdl2xx.hpp>
#include <sdl2xx/mixer.hpp>
#include <iostream>
#include <cstdlib>

namespace Mix = SDL::Mix;

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_EVENTS) < 0) {
		std::cerr << SDL_GetError() << std::endl;
		return 1;
	};
	std::atexit([]() {
		SDL_Quit();
	});

	if (!(Mix_Init(MIX_INIT_OGG) & MIX_INIT_OGG)) {
		std::cerr << Mix_GetError() << std::endl;
		return 1;
	}
	std::atexit([]() {
		Mix_Quit();
	});

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
		std::cerr << Mix_GetError() << std::endl;
		return 1;
	}
	std::atexit([]() {
		Mix_CloseAudio();
	});

	auto m = Mix::LoadMUS("wilhelm_scream.ogg");
	if (Mix_PlayMusic(m.get(), -1) == -1) {
		std::cerr << Mix_GetError() << std::endl;
		return 1;
	}

	for(;;) {
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				break;
			}
		}
	}
}
