#ifndef _SDL2XX__TTF_HPP__
#define _SDL2XX__TTF_HPP__

namespace SDL {
namespace TTF {

	using Font = std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)>;

	inline Font OpenFont(const char* file, int ptsize) {
		return impl::Create(TTF_OpenFont, TTF_CloseFont, file, ptsize);
	}

	inline Font OpenFont(const char* file, int ptsize, long index) {
		return impl::Create(TTF_OpenFontIndex, TTF_CloseFont, file, ptsize, index);
	}

	inline Font OpenFont(SDL_RWops* src, int freesrc, int ptsize) {
		return impl::Create(TTF_OpenFontRW, TTF_CloseFont, src, freesrc, ptsize);
	}

	inline Font OpenFont(SDL_RWops* src, int freesrc, int ptsize, long index) {
		return impl::Create(TTF_OpenFontIndexRW, TTF_CloseFont, src, freesrc, ptsize, index);
	}

	inline Surface RenderTextSolid(TTF_Font* font, const char* text, SDL_Color fg) {
		return impl::Create(TTF_RenderUTF8_Solid, SDL_FreeSurface, font, text, fg);
	}

	inline Surface RenderTextSolid(TTF_Font* font, const Uint16* text, SDL_Color fg) {
		return impl::Create(TTF_RenderUNICODE_Solid, SDL_FreeSurface, font, text, fg);
	}

	inline Surface RenderTextShaded(TTF_Font* font, const char* text, SDL_Color fg, SDL_Color bg) {
		return impl::Create(TTF_RenderUTF8_Shaded, SDL_FreeSurface, font, text, fg, bg);
	}

	inline Surface RenderTextShaded(TTF_Font* font, const Uint16* text, SDL_Color fg, SDL_Color bg) {
		return impl::Create(TTF_RenderUNICODE_Shaded, SDL_FreeSurface, font, text, fg, bg);
	}

	inline Surface RenderTextBlended(TTF_Font* font, const char* text, SDL_Color fg) {
		return impl::Create(TTF_RenderUTF8_Blended, SDL_FreeSurface, font, text, fg);
	}

	inline Surface RenderTextBlended(TTF_Font* font, const Uint16* text, SDL_Color fg) {
		return impl::Create(TTF_RenderUNICODE_Blended, SDL_FreeSurface, font, text, fg);
	}

	inline Surface RenderGlyphSolid(TTF_Font* font, Uint16 ch, SDL_Color fg) {
		return impl::Create(TTF_RenderGlyph_Solid, SDL_FreeSurface, font, ch, fg);
	}

	inline Surface RenderGlyphShaded(TTF_Font* font, Uint16 ch, SDL_Color fg, SDL_Color bg) {
		return impl::Create(TTF_RenderGlyph_Shaded, SDL_FreeSurface, font, ch, fg, bg);
	}

	inline Surface RenderGlyphBlended(TTF_Font* font, Uint16 ch, SDL_Color fg) {
		return impl::Create(TTF_RenderGlyph_Blended, SDL_FreeSurface, font, ch, fg);
	}

}
}

#endif /* _SDL2XX__TTF_HPP__ */
