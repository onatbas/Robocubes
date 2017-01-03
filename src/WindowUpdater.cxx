//
// Created by Onat Bas on 03/01/17.
//

#include <WindowRefGetter.hxx>
#include "BoxDrawer.hxx"
#include "WindowUpdater.hxx"

void WindowUpdater::updateWindow(const Window *window) const {
    WindowRefGetter windowGetter(window);
    SDL_UpdateWindowSurface(windowGetter.getWindowRef());
}