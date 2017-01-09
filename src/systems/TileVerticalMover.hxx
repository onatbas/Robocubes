//
// Created by Onat Bas on 06/01/17.
//

#ifndef BOXESGAME_TILEVERTICALMOVER_HXX
#define BOXESGAME_TILEVERTICALMOVER_HXX

#include "systems/GameSystem.hxx"
#include "decorators/GameLooper.hxx"
#include "delegates/SingleDataHolder.hxx"

class TileVerticalMover : public GameSystem<TileVerticalMover> {
public:
    TileVerticalMover(StackSet &set, GameLooper &looper);
public:
    virtual void
    update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) override;

private:
    void markVerticalMovingTiles(entityx::EntityManager &entities, BoxPosition &clicked);
    void moveOffsets(entityx::EntityManager &manager, entityx::TimeDelta dt);
    StackSet &set;
    GameLooper &looper;

    SingleDataHolder<BoxPosition> clicked;
};

#endif //BOXESGAME_TILEVERTICALMOVER_HXX
