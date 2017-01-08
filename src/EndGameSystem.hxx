//
// Created by Onat Bas on 08/01/17.
//

#ifndef BOXESGAME_ENDGAMESYSTEM_HXX
#define BOXESGAME_ENDGAMESYSTEM_HXX

#include "GameSystem.hxx"
#include "Dimension.hxx"
#include "GameLooper.hxx"
#include "StackSet.hxx"

class EndGameSystem : public GameSystem<EndGameSystem> {
public:
    EndGameSystem(int endGameColumn, Dimension windowDimensions, GameLooper *looper, StackSet *set);
    virtual void
    update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) override;

private:
    GameLooper *looper;
    int endGameColumn;
    Dimension windowDimensions;
    StackSet *set;
};

#endif //BOXESGAME_ENDGAMESYSTEM_HXX
