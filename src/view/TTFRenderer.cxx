//
// Created by Onat Bas on 08/01/17.
//

#include "TTFRenderer.hxx"

TTFRenderer::TTFRenderer(Renderable *renderable, TTF_Font *font) : renderable(renderable),
                                                                   font(font) {
}

void TTFRenderer::draw(std::string text, DrawPosition position) {
    SDL_Color color = SDL_Color();
    SDL_Surface* textSurface = TTF_RenderText_Solid( font, text.c_str(), color );

    SDL_Rect drawAt;
    drawAt.x = position.getX();
    drawAt.y = position.getY();
    drawAt.w = textSurface->w;
    drawAt.h = textSurface->h;

    SDL_Rect drawFrom;
    drawFrom.x = 0;
    drawFrom.y = 0;
    drawFrom.w = textSurface->w;
    drawFrom.h = textSurface->h;

    renderable->draw(textSurface, drawAt, drawFrom);

    SDL_FreeSurface(textSurface);
}
