//
// Created by Onat Bas on 03/01/17.
//

#include <WindowRefGetter.hxx>
#include "BoxDrawer.hxx"

void WindowUpdater::updateWindow(const Window *window) const {
    WindowRefGetter windowGetter(window);
    SDL_UpdateWindowSurface(windowGetter.getWindowRef());
}

WindowUpdater::WindowUpdater(GameLooper *looper, const Window *window) {
    looper->observe(BOXESEVENT_LEAVE_FRAME, 0, [=](const char *e) {
        updateWindow(window);
    });
}

WindowUpdater::WindowUpdater() {
}
