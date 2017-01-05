//
// Created by Onat Bas on 03/01/17.
//

#include <SDL2/SDL_events.h>
#include "GameLooper.hxx"

#include <iostream>

void GameLooper::loop() {
    SDL_Event event;
    while (!shouldExit) {

        (*getSignal(BOXESEVENT_ENTER_FRAME, 0))(event);
        while(SDL_PollEvent(&event)){
            (*getSignal(event.type, 0))(event);
            (*getSignal(event.type, event.window.event))(event);
        }
        (*getSignal(BOXESEVENT_LEAVE_FRAME, 0))(event);
        SDL_Delay(5);
    }
}

void GameLooper::observe(Type type, SubType event, Callback callback) {
    getSignal(type, event)->connect(callback);
}

Signal &GameLooper::getSignal(Type type, SubType event) {
    std::tuple<Type, SubType> tuple = std::make_tuple(type, event);
    Signal &s = observers[tuple];
    if (s == nullptr)
        s = std::make_shared<boost::signals2::signal<CALLBACK>>();
    return s;
}

void GameLooper::exit() {
    shouldExit = true;
}

GameLooper::GameLooper() : shouldExit(false){
}
