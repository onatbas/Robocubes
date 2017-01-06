//
// Created by Onat Bas on 06/01/17.
//

#ifndef BOXESGAME_TILEVERTICALMOVER_HXX
#define BOXESGAME_TILEVERTICALMOVER_HXX

#include "GameSystem.hxx"

class TileVerticalMover : public GameSystem<TileVerticalMover> {
public:
    TileVerticalMover(StackSet &set);
public:
    virtual void
    update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) override;
    StackSet &set;

private:
    void markVerticalMovingTiles(entityx::EntityManager &entities);
    void moveOffsets(entityx::EntityManager &manager, entityx::TimeDelta dt);
};

#endif //BOXESGAME_TILEVERTICALMOVER_HXX
