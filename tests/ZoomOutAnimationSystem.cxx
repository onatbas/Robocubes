//
// Created by Onat Bas on 05/01/17.
//

#include <Scale.hxx>
#include <GameBeginZoomOut.hxx>
#include <SDL2/SDL_timer.h>
#include <BackgroundComponent.hxx>
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

                s.scale *= z.getScaleFactor();
                if (std::abs(s.scale - z.getSetZoomTo()) < 0.01)
                    e.remove<GameBeginZoomOut>();
                else{
                    std::cout << s.scale << std::endl;
                }

            }
        }
    });

}
