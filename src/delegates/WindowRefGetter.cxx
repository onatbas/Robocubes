//
// Created by Onat Bas on 03/01/17.
//

#include "WindowRefGetter.hxx"

SDL_Window *WindowRefGetter::getWindowRef() const {
    return window->pWindow;
}

WindowRefGetter::WindowRefGetter(const Window *wind) : window(wind) {
}
