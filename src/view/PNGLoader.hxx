//
// Created by Onat Bas on 03/01/17.
//

#ifndef BOXESGAME_PNGLOADER_HXX
#define BOXESGAME_PNGLOADER_HXX

#include <string>
#include "PNG.hxx"
#include "PNG.hxx"
#include <string>
#include <SDL2/SDL_surface.h>
#include <SDL_image.h>
#include <Window.hxx>
#include <WindowRefGetter.hxx>

class PNGLoader {
public:
    PNG load(std::string pathToPng, const Window *window) const;
};

#endif //BOXESGAME_PNGLOADER_HXX
