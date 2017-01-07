//
// Created by Onat Bas on 07/01/17.
//

#include "StackInsertionSystem.hxx"
#include "MovementChecker.hxx"
#include "VerticalMovement.hxx"
#include "HorizontalMovement.hxx"

bool MovementChecker::isSomethingMoving(entityx::EntityManager &entities) const {//Check if anything is moving.
    bool somethingMoving = false;
    entities.each<VerticalMovement>([&](entityx::Entity entity, VerticalMovement &movement){
                somethingMoving = true;
            });
    entities.each<HorizontalMovement>([&](entityx::Entity entity, HorizontalMovement &movement){
                somethingMoving = true;
            });
    return somethingMoving;
}