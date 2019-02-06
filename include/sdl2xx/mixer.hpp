#ifndef _SDL2XX__MIXER_HPP__
#define _SDL2XX__MIXER_HPP__

namespace SDL {
namespace Mix {

	using Chunk = std::unique_ptr<Mix_Chunk, decltype(&Mix_FreeChunk)>;
	using Music = std::unique_ptr<Mix_Music, decltype(&Mix_FreeMusic)>;

	inline Chunk LoadWAV(SDL_RWops* src, int freesrc) {
		return impl::Create(Mix_LoadWAV_RW, Mix_FreeChunk, src, freesrc);
	}

	inline Chunk LoadWAV(const char* file) {
		return Mix::LoadWAV(SDL_RWFromFile(file, "rb"), 1);
	}

	inline Chunk LoadWAV(Uint8* mem) {
		return impl::Create(Mix_QuickLoad_WAV, Mix_FreeChunk, mem);
	}

	inline Chunk LoadRAW(Uint8* mem, Uint32 len) {
		return impl::Create(Mix_QuickLoad_RAW, Mix_FreeChunk, mem, len);
	}

	inline Music LoadMUS(const char* file) {
		return impl::Create(Mix_LoadMUS, Mix_FreeMusic, file);
	}

}
}

#endif /* _SDL2XX__MIXER_HPP__ */
