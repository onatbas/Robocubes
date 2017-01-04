//
// Created by Onat Bas on 04/01/17.
//

#include <SDL_events.h>
#include "LoopTerminator.hxx"

LoopTerminator::LoopTerminator(GameLooper &looper) {
    looper.observe(SDL_QUIT, 0, [&](SDL_Event e) {
        looper.exit();
    });
}
