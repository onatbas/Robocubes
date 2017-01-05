//
// Created by Onat Bas on 03/01/17.
//

#include <SDL2/SDL.h>
#include <iostream>
#include "WindowOpener.hxx"

std::shared_ptr<Window> WindowOpener::open() const {
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    }
    SDL_Window *window = SDL_CreateWindow("Hello World!", 100, 100, 1024, 680, SDL_WINDOW_SHOWN /* | SDL_WINDOW_RESIZABLE*/);
    WindowPositioner positioner;
    positioner.position(window);
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_FillRect( surface, NULL, SDL_MapRGB( surface->format, 0xFF, 0xFF, 0xFF ) );
    SDL_UpdateWindowSurface( window );

    auto result = std::make_shared<Window>(window);
    return result;
}

