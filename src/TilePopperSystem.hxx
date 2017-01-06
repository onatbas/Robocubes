//
// Created by Onat Bas on 06/01/17.
//

#ifndef BOXESGAME_TILEPOPPERSYSTEM_HXX
#define BOXESGAME_TILEPOPPERSYSTEM_HXX

#include "GameSystem.hxx"
#include "StackSet.hxx"
#include "MouseClicked.hxx"
#include "Window.hxx"
#include "SmokeAdder.hxx"

class TilePopperSystem : public GameSystem<TilePopperSystem>{
public:
    virtual void
    update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) override;

    TilePopperSystem(StackSet *set, Window *window);
private:
    StackSet *set;
    Window *window;

    std::vector<BoxPosition> getNeighbours(const MouseClicked &clicked) const;
    void markBoxesToPop(entityx::EntityManager &entities) const;
    void makePoppedDisappear(entityx::EntityManager &entities) const;
};

#endif //BOXESGAME_TILEPOPPERSYSTEM_HXX
