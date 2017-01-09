//
// Created by Onat Bas on 08/01/17.
//

#ifndef BOXESGAME_TTFRENDERER_HXX
#define BOXESGAME_TTFRENDERER_HXX

#include <string>
#include <SDL_ttf.h>
#include "Renderable.hxx"
#include "components/DrawPosition.hxx"

class TTFRenderer {

public:
    void draw(std::string text, DrawPosition position);

private:
public:
    TTFRenderer(Renderable *renderable, TTF_Font *font);
private:
    Renderable *renderable;
    TTF_Font *font;
};

#endif //BOXESGAME_TTFRENDERER_HXX
