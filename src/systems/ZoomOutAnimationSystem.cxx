//
// Created by Onat Bas on 05/01/17.
//

#include <components/Scale.hxx>
#include <systems/GameBeginZoomOut.hxx>
#include <SDL2/SDL_timer.h>
#include <components/BackgroundComponent.hxx>
#include "ZoomOutAnimationSystem.hxx"
#include <iostream>

void
ZoomOutAnimationSystem::update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) {
    entities.each<Scale, GameBeginZoomOut>([&](entityx::Entity e, Scale &s, GameBeginZoomOut &z) {
        if (z.startedListening == 0) {
            z.startedListening = SDL_GetTicks();
            z.oldScale = s.scale;
        } else {
            z.waitedDuration += dt;
            const float durationToWait = z.getDurationToWait();
            if (z.waitedDuration >= durationToWait) {
                const float to = z.getSetZoomTo();

                s.scale = (to - s.scale) * z.getScaleFactor()  + s.scale;
                if (std::abs(s.scale - to) < 0.01) {
                    e.remove<GameBeginZoomOut>();
                    s.scale = to;
                }
            }
        }
    });

}
