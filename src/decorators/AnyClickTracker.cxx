//
// Created by Onat Bas on 08/01/17.
//

#include "AnyClickTracker.hxx"

AnyClickTracker::AnyClickTracker(GameLooper *looper, std::function<void()> callback) {
    looper->observe(SDL_MOUSEBUTTONUP, 0, [&](const char *data){
        callback();
    });
}
