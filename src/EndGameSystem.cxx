//
// Created by Onat Bas on 08/01/17.
//

#include "EndGameSystem.hxx"
#include "BoxPosition.hxx"
#include "MovementChecker.hxx"
#include "Box.hxx"
#include "AnimationSet.hxx"
#include "ResourceUtil.hxx"
#include "BoxDrawingConfiguration.hxx"
#include "DrawPosition.hxx"
#include "BoxPositionCalculator.hxx"
#include "Velocity.hxx"
#include "GameLooper.hxx"
#include "StackSet.hxx"
#include "NeighboursInVicinityCounter.hxx"

void EndGameSystem::update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) {
    bool endGame = false;
    MovementChecker checker;
    if (checker.isSomethingMoving(entities))
        return;

    bool noMoreMoves = true;
    entities.each<Box, BoxPosition>([&](entityx::Entity entity, Box &box, BoxPosition &position){

        NeighboursInVicinityCounter counter;
        if (counter.hasEnoughNeighbours(*set, position, box.getColor()))
            noMoreMoves = false;

        if (position.getX() < endGameColumn)
            return;

        endGame = true;

        auto animated = entities.create();
        AnimationSet set;
        ResourceUtil util;
        BoxDrawingConfiguration config;
        BoxPositionCalculator calculator;
        set.addSprite(util.getBoxPath(box, false), config.getBoxFinalScale());
        set.setOneShot(false);
        animated.assign_from_copy<AnimationSet>(set);
        animated.assign<DrawPosition>(calculator.boxToDrawing(position, windowDimensions, config.getBoxFinalScale()));
        animated.assign<Velocity>(0, 12, position.getY() * 10);

        entity.destroy();
    });

    if (endGame || noMoreMoves)
        looper->sendSignal(BOXESGAME_ENDGAME, 0, nullptr);
}

EndGameSystem::EndGameSystem(int endGameColumn, Dimension windowDimensions, GameLooper *looper, StackSet *set)
        : endGameColumn(endGameColumn),
          windowDimensions(windowDimensions),
          looper(looper),
          set(set){

}
