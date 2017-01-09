//
// Created by Onat Bas on 05/01/17.
//

#ifndef BOXESGAME_ZOOMOUTANIMATIONSYSTEM_HXX
#define BOXESGAME_ZOOMOUTANIMATIONSYSTEM_HXX

#include "GameSystem.hxx"

class ZoomOutAnimationSystem : public GameSystem<ZoomOutAnimationSystem> {
public:
    virtual void
    update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) override;
};

#endif //BOXESGAME_ZOOMOUTANIMATIONSYSTEM_HXX
