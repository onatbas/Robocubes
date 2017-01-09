//
// Created by Onat Bas on 03/01/17.
//

#include <SDL2/SDL_video.h>
#include <SDL2/SDL.h>
#include "Window.hxx"

Window::Window(SDL_Window *pWindow) {
    this->pWindow = pWindow;
}

bool Window::is_open() const {
    return pWindow != nullptr;
}

Window::~Window() {
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
}
