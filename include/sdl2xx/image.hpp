#ifndef _SDL2XX__IMAGE_HPP__
#define _SDL2XX__IMAGE_HPP__

namespace SDL {
namespace Image {

	inline Surface Load(const char* file) {
		return impl::Create(IMG_Load, SDL_FreeSurface, file);
	}

	inline Surface Load(SDL_RWops* src, int freesrc) {
		return impl::Create(IMG_Load_RW, SDL_FreeSurface, src, freesrc);
	}

	inline Surface Load(SDL_RWops* src, int freesrc, const char* type) {
		return impl::Create(IMG_LoadTyped_RW, SDL_FreeSurface, src, freesrc, type);
	}

	inline Texture LoadTexture(SDL_Renderer* renderer, const char* file) {
		return impl::Create(IMG_LoadTexture, SDL_DestroyTexture, renderer, file);
	}

	inline Texture LoadTexture(SDL_Renderer* renderer, SDL_RWops* src, int freesrc) {
		return impl::Create(IMG_LoadTexture_RW, SDL_DestroyTexture, renderer, src, freesrc);
	}

	inline Texture LoadTexture(SDL_Renderer* renderer, SDL_RWops* src, int freesrc, const char* type) {
		return impl::Create(IMG_LoadTextureTyped_RW, SDL_DestroyTexture, renderer, src, freesrc, type);
	}

}
}

#endif /* _SDL2XX__IMAGE_HPP__ */
