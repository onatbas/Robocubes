//
// Created by Onat Bas on 04/01/17.
//

#include <GameLooper.hxx>
#include "EntityFactory.hxx"

EntityFactory::EntityFactory(GameLooper *looper) : looper(looper), active(true) {
    looper->observe(BOXESEVENT_ENTER_FRAME, 0, [&](const char *e) {
        update(10);
    });
}

void EntityFactory::update(entityx::TimeDelta dt) {
    if (!active) return;
    for (auto f : systemUpdates)
        f(dt);
}

void EntityFactory::setActive(bool active) {
    EntityFactory::active = active;
}
