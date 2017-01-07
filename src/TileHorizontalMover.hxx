//
// Created by Onat Bas on 07/01/17.
//

#ifndef BOXESGAME_TILEHORIZONTALMOVER_HXX
#define BOXESGAME_TILEHORIZONTALMOVER_HXX

#include <StackSet.hxx>
#include "entityx/entityx.h"
#include "GameSystem.hxx"
#include "SingleDataHolder.hxx"
#include "HorizontalMovements.hxx"

class TileHorizontalMover : public GameSystem<TileHorizontalMover>{
private:
    StackSet &set;
    GameLooper &looper;
public:
    TileHorizontalMover(StackSet &set, GameLooper &looper);
    virtual void
    update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) override;

private:
    SingleDataHolder<HorizontalMovements> movements;
    bool verticalMovesEnded;
};

#endif //BOXESGAME_TILEHORIZONTALMOVER_HXX
