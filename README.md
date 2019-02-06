# sdl2xx

A minimalistic SDL2 C++14 wrapper, all in a single header*! It only concerns itself with resource acquisition.

* Additional headers available for SDL_image, SDL_mixer, SDL_net, and SDL_ttf.

## Usage (build-tool agnostic)
Simply drop the header somewhere in your include path. You will need to provide SDL2 linking and `-std=c++14`.

## Usage (CMake)

```cmake
add_subdirectory(vendor/sdl2xx)
find_package(SDL2 REQUIRED)
target_link_libraries(foo sdl2xx SDL2::SDL2)
```

## Example

```c++
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
```


