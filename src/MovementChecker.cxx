//
// Created by Onat Bas on 07/01/17.
//

#include "StackInsertionSystem.hxx"
#include "VerticalMovement.hxx"
#include "HorizontalMovement.hxx"
#include "GameBeginZoomOut.hxx"

bool MovementChecker::isSomethingMoving(entityx::EntityManager &entities) const {//Check if anything is moving.
    bool somethingMoving = false;


    if (!somethingMoving)
        entities.each<VerticalMovement>([&](entityx::Entity entity, VerticalMovement &movement) {
        somethingMoving = true;
    });

    if (!somethingMoving)
    entities.each<HorizontalMovement>([&](entityx::Entity entity, HorizontalMovement &movement) {
        somethingMoving = true;
    });

    if (!somethingMoving)
    entities.each<GameBeginZoomOut>([&](entityx::Entity entity, GameBeginZoomOut &movement) {
        somethingMoving = true;
    });

    return somethingMoving;
}