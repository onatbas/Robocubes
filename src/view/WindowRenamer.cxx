//
// Created by Onat Bas on 03/01/17.
//

#include <SDL2/SDL_video.h>
#include "WindowRenamer.hxx"
#include "delegates/WindowRefGetter.hxx"

void WindowRenamer::rename(std::shared_ptr<Window> window, std::string name) const {
    WindowRefGetter getter(window.get());
    SDL_SetWindowTitle(getter.getWindowRef(), name.c_str());
}
