//
// Created by Onat Bas on 04/01/17.
//

#include "delegates/BackgroundRendererEntityFactory.hxx"
#include "WindowDimensionGetter.hxx"
#include "WindowRefGetter.hxx"

Dimension WindowDimensionGetter::getDimensionsOfWindows(const Window *window) const {
    WindowRefGetter getter(window);
    int w,h;
    SDL_GetWindowSize(getter.getWindowRef(), &w, &h);
    return Dimension(w, h);
}