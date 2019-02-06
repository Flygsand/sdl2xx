#ifndef __SDL2XX_HPP___
#define __SDL2XX_HPP___

#include <memory>
#include <utility>
#include <system_error>
#include <type_traits>

namespace SDL {
	namespace impl {

		template<typename Creator, typename Destructor, typename... Arguments>
		auto Create(Creator c, Destructor d, Arguments&&... args) {
			auto r = c(::std::forward<Arguments>(args)...);
			if (!r) {
				throw ::std::system_error(errno, ::std::generic_category(), SDL_GetError());
			}
			return ::std::unique_ptr<::std::decay_t<decltype(*r)>, decltype(d)>(r, d);
		}
	}

	using Buffer = std::unique_ptr<Uint8, decltype(&SDL_free)>;
	using Cond = std::unique_ptr<SDL_cond, decltype(&SDL_DestroyCond)>;
	using Cursor = std::unique_ptr<SDL_Cursor, decltype(&SDL_FreeCursor)>;
	using Mutex = std::unique_ptr<SDL_mutex, decltype(&SDL_DestroyMutex)>;
	using Palette = std::unique_ptr<SDL_Palette, decltype(&SDL_FreePalette)>;
	using PixelFormat = std::unique_ptr<SDL_PixelFormat, decltype(&SDL_FreeFormat)>;
	using Renderer = std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>;
	using RWops = std::unique_ptr<SDL_RWops, decltype(&SDL_FreeRW)>;
	using Semaphore = std::unique_ptr<SDL_sem, decltype(&SDL_DestroySemaphore)>;
	using Surface = std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)>;
	using Texture = std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>;
	using Window = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;

	inline Cond CreateCond() {
		return impl::Create(SDL_CreateCond, SDL_DestroyCond);
	}

	inline Cursor CreateCursor(const Uint8* data, const Uint8* mask, int w, int h, int hotX, int hotY) {
		return impl::Create(SDL_CreateCursor, SDL_FreeCursor, data, mask, w, h, hotX, hotY);
	}

	inline Cursor CreateCursor(SDL_SystemCursor id) {
		return impl::Create(SDL_CreateSystemCursor, SDL_FreeCursor, id);
	}

	inline Cursor CreateCursor(SDL_Surface* surface, int hotX, int hotY) {
		return impl::Create(SDL_CreateColorCursor, SDL_FreeCursor, surface, hotX, hotY);
	}

	inline Mutex CreateMutex() {
		return impl::Create(SDL_CreateMutex, SDL_DestroyMutex);
	}

	inline Palette CreatePalette(int ncolors) {
		return impl::Create(SDL_AllocPalette, SDL_FreePalette, ncolors);
	}

	inline PixelFormat CreatePixelFormat(Uint32 pixelFormat) {
		return impl::Create(SDL_AllocFormat, SDL_FreeFormat, pixelFormat);
	}

	inline Renderer CreateRenderer(SDL_Window* window, int index, Uint32 flags) {
		return impl::Create(SDL_CreateRenderer, SDL_DestroyRenderer, window, index, flags);
	}

	inline Renderer CreateRenderer(SDL_Surface* surface) {
		return impl::Create(SDL_CreateSoftwareRenderer, SDL_DestroyRenderer, surface);
	}

	inline RWops CreateRWops() {
		return impl::Create(SDL_AllocRW, SDL_FreeRW);
	}

	inline Semaphore CreateSemaphore(Uint32 initialValue) {
		return impl::Create(SDL_CreateSemaphore, SDL_DestroySemaphore, initialValue);
	}

	inline Surface CreateRGBSurface(Uint32 flags, int width, int height, int depth, Uint32 rmask, Uint32 gmask, Uint32 bmask, Uint32 amask) {
		return impl::Create(SDL_CreateRGBSurface, SDL_FreeSurface, flags, width, height, depth, rmask, gmask, bmask, amask);
	}

	inline Surface CreateRGBSurface(void* pixels, int width, int height, int depth, int pitch, Uint32 rmask, Uint32 gmask, Uint32 bmask, Uint32 amask) {
		return impl::Create(SDL_CreateRGBSurfaceFrom, SDL_FreeSurface, pixels, width, height, depth, pitch, rmask, gmask, bmask, amask);
	}

	inline Surface CreateRGBSurface(Uint32 flags, int width, int height, int depth, Uint32 format) {
		return impl::Create(SDL_CreateRGBSurfaceWithFormat, SDL_FreeSurface, flags, width, height, depth, format);
	}

	inline Surface CreateRGBSurface(void* pixels, int width, int height, int depth, int pitch, Uint32 format) {
		return impl::Create(SDL_CreateRGBSurfaceWithFormatFrom, SDL_FreeSurface, pixels, width, height, depth, pitch, format);
	}

	inline Texture CreateTexture(SDL_Renderer* renderer, Uint32 format, int access, int w, int h) {
		return impl::Create(SDL_CreateTexture, SDL_DestroyTexture, renderer, format, access, w, h);
	}

	inline Texture CreateTexture(SDL_Renderer* renderer, SDL_Surface* surface) {
		return impl::Create(SDL_CreateTextureFromSurface, SDL_DestroyTexture, renderer, surface);
	}

	inline Window CreateWindow(const char* title, int x, int y, int w, int h, Uint32 flags) {
		return impl::Create(SDL_CreateWindow, SDL_DestroyWindow, title, x, y, w, h, flags);
	}

	inline Window CreateWindow(const void* data) {
		return impl::Create(SDL_CreateWindowFrom, SDL_DestroyWindow, data);
	}

}

#endif /* __SDL2XX_HPP___ */
