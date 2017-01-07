//
// Created by Onat Bas on 03/01/17.
//

#include <SDL2/SDL_events.h>
#include "GameLooper.hxx"

#include <iostream>

void GameLooper::loop() {
    SDL_Event event;
    while (!shouldExit) {

        sendSignal(BOXESEVENT_ENTER_FRAME, 0, (char *)&event);
        while(SDL_PollEvent(&event)){
            if (event.window.event != 0)
                sendSignal(event.type, 0, (char *)&event);
            sendSignal(event.type, event.window.event, (char *)&event);
        }
        sendSignal(BOXESEVENT_LEAVE_FRAME, 0, (char *)&event);
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

void GameLooper::sendSignal(Type type, SubType event, const char *e)
{
    (*getSignal(type, event))(e);
}