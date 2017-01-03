//
// Created by Onat Bas on 03/01/17.
//

#include "PNGLoader.hxx"
#include <iostream>

PNG PNGLoader::load(std::string pathToPng, const Window *window) const {
    SDL_Surface *optimizedSurface = nullptr;
    {
        SDL_Surface *png = IMG_Load(pathToPng.c_str());
        const WindowRefGetter &getter = WindowRefGetter(window);
        SDL_Window *const pWindow = getter.getWindowRef();
        SDL_Surface *const pSurface = SDL_GetWindowSurface(pWindow);
        optimizedSurface = SDL_ConvertSurface(png, pSurface->format, NULL);
        SDL_FreeSurface(png);
    }


    if (optimizedSurface == nullptr) {
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
    }

    return PNG(optimizedSurface);
}
