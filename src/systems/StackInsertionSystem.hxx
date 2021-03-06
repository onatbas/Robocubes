//
// Created by Onat Bas on 07/01/17.
//

#ifndef BOXESGAME_STACKINSERTIONSYSTEM_HXX
#define BOXESGAME_STACKINSERTIONSYSTEM_HXX

#include "GameSystem.hxx"
#include "logic/StackSet.hxx"
#include "decorators/GameLooper.hxx"
#include "delegates/SingleDataHolder.hxx"
#include "components/BoxPosition.hxx"
#include "delegates/MovementChecker.hxx"

class StackInsertionSystem : public GameSystem<StackInsertionSystem>{
public:
    StackInsertionSystem(StackSet &set, GameLooper &looper, int roundsForInsertion);
    virtual void
    update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) override;

private:
    StackSet &set;
    GameLooper &looper;
    int roundsForInsertion;
    int currentRound;

    SingleDataHolder<BoxPosition> lastClick;

    bool shouldInsert;
    void insertNewColumn(entityx::EntityManager &entities);
    void checkShouldInsert();
};

#endif //BOXESGAME_STACKINSERTIONSYSTEM_HXX
