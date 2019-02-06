#include <SDL.h>
#include <SDL_net.h>
#include <sdl2xx.hpp>
#include <sdl2xx/net.hpp>
#include <iostream>
#include <cstdlib>
#include <string>

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_EVENTS) < 0) {
		std::cerr << SDL_GetError() << std::endl;
		return 1;
	}
	std::atexit([]() {
		SDL_Quit();
	});

	if (SDLNet_Init() == -1) {
		std::cerr << SDLNet_GetError() << std::endl;
		return 1;
	}
	std::atexit([]() {
		SDLNet_Quit();
	});

	IPaddress ip;
	if (SDLNet_ResolveHost(&ip, "www.libsdl.org", 80) == -1) {
		std::cerr << SDLNet_GetError() << std::endl;
		return 1;
	}

	auto s = SDL::Net::CreateTCPSocket(&ip);
	std::string req {"GET / HTTP/1.1\r\nHost: www.libsdl.org\r\n\r\n"};
	if (SDLNet_TCP_Send(s.get(), req.c_str(), req.length() + 1) < req.length() + 1) {
		std::cerr << SDLNet_GetError() << std::endl;
		return 1;
	}

	char res[8192] = {0};
	if (SDLNet_TCP_Recv(s.get(), &res, 8191) <= 0) {
		std::cerr << SDLNet_GetError() << std::endl;
		return 1;
	}

	std::cout << res << std::endl;
}
