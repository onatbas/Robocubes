//
// Created by Onat Bas on 06/01/17.
//

#include "BoxPositionCalculator.hxx"
#include "TilePopperSystem.hxx"
#include "SmokeAdder.hxx"
#include "ResourceUtil.hxx"
#include "../tests/AnimationSet.hxx"

void SmokeAdder::add(entityx::EntityManager &entities, const DrawPosition &drawPosition) const {
    ResourceUtil util;
    entityx::Entity smokeEntity = entities.create();
    AnimationSet animations;
    animations.setPassInterval(100);
    animations.setOneShot(true);
    animations.addSprite(util.getRandomSmoke(), Scale(0.15));
    animations.addSprite(util.getRandomSmoke(), Scale(0.20));
    animations.addSprite(util.getRandomSmoke(), Scale(0.25));
    animations.addSprite(util.getRandomSmoke(), Scale(0.13));
    animations.addSprite(util.getRandomSmoke(), Scale(0.04));

    smokeEntity.assign_from_copy<AnimationSet>(animations);
    smokeEntity.assign_from_copy(drawPosition);
}