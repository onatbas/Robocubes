//
// Created by Onat Bas on 06/01/17.
//

#include "systems/RenderingSystem.hxx"
#include "WindowRefGetter.hxx"

void WindowCleaner::clean(Renderable &renderable, Window *window) const {
    WindowRefGetter getter(window);
    SDL_Surface *const pSurface = SDL_GetWindowSurface(getter.getWindowRef());
    SDL_FillRect(pSurface, NULL, SDL_MapRGB(pSurface->format, 0xD0, 0xF4, 0xF7));
}