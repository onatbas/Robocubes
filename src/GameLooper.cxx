//
// Created by Onat Bas on 03/01/17.
//

#include <SDL2/SDL_events.h>
#include "GameLooper.hxx"

void GameLooper::loop() {
    SDL_Event event;
    while ((!shouldExit) && (SDL_WaitEvent(&event))) {
        (*getSignal(event.type, 0))(event);
        (*getSignal(event.type, event.window.event))(event);
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
