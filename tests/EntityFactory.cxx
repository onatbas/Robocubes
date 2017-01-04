//
// Created by Onat Bas on 04/01/17.
//

#include <GameLooper.hxx>
#include "EntityFactory.hxx"

EntityFactory::EntityFactory(GameLooper *looper) : looper(looper) {
    looper->observe(BOXESEVENT_ENTER_FRAME, 0, [&](SDL_Event e){
        update(100);
    });
}

void EntityFactory::update(entityx::TimeDelta dt) {
    for (auto f : systemUpdates)
        f(dt);
}
