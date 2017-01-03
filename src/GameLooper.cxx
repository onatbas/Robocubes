//
// Created by Onat Bas on 03/01/17.
//

#include <SDL2/SDL_events.h>
#include "GameLooper.hxx"

void GameLooper::loop() const {
    bool done = false;
    SDL_Event event;

    while ((!done) && (SDL_WaitEvent(&event))) {
        switch (event.type) {
            case SDL_QUIT:
                done = true;
                break;

            default:
                break;
        }   // End switch

    }   // End while

}