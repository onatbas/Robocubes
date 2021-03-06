//
// Created by Onat Bas on 05/01/17.
//

#ifndef BOXESGAME_MOUSECLICKTRACKER_HXX
#define BOXESGAME_MOUSECLICKTRACKER_HXX

#include "GameLooper.hxx"
#include "EntityFactory.hxx"
#include "components/Dimension.hxx"
#include "systems/GameSystem.hxx"
#include "delegates/SingleDataHolder.hxx"
#include "components/BoxPosition.hxx"

class MouseClickTracker : public GameSystem<MouseClickTracker> {

public:
    MouseClickTracker(GameLooper *looper, EntityFactory *factory, Dimension windowDimensions);
    virtual void
    update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) override;
private:
    GameLooper &looper;
    SingleDataHolder<BoxPosition> clickPosition;
    bool endGame;
};

#endif //BOXESGAME_MOUSECLICKTRACKER_HXX
