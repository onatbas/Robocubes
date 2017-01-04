//
// Created by Onat Bas on 03/01/17.
//

#include <WindowRefGetter.hxx>
#include "BoxDrawer.hxx"

#include <iostream>

void WindowUpdater::updateWindow(const Window *window) const {
    WindowRefGetter windowGetter(window);
    std::cout << window << std::endl;
    SDL_UpdateWindowSurface(windowGetter.getWindowRef());
}

WindowUpdater::WindowUpdater(GameLooper *looper, const Window *window) {
    looper->observe(BOXESEVENT_LEAVE_FRAME, 0, [=](SDL_Event e) {
        updateWindow(window);
    });
}

WindowUpdater::WindowUpdater() {
}
