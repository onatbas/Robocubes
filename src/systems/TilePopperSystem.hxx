//
// Created by Onat Bas on 06/01/17.
//

#ifndef BOXESGAME_TILEPOPPERSYSTEM_HXX
#define BOXESGAME_TILEPOPPERSYSTEM_HXX

#include "systems/GameSystem.hxx"
#include "logic/StackSet.hxx"
#include "components/MouseClicked.hxx"
#include "view/Window.hxx"
#include "view/SmokeAdder.hxx"
#include "GameLooper.hxx"
#include "delegates/SingleDataHolder.hxx"

class TilePopperSystem : public GameSystem<TilePopperSystem> {
public:
    virtual void
    update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) override;

    TilePopperSystem(StackSet *set, Window *window, GameLooper *looper);
private:
    GameLooper *looper;
    StackSet *set;
    Window *window;

    std::vector<BoxPosition> getNeighbours(const MouseClicked &clicked) const;
    void markBoxesToPop(entityx::EntityManager &entities, BoxPosition clicked) const;
    void makePoppedDisappear(entityx::EntityManager &entities) const;
    SingleDataHolder<BoxPosition> clicked;
};

#endif //BOXESGAME_TILEPOPPERSYSTEM_HXX
