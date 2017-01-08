//
// Created by Onat Bas on 06/01/17.
//

#include "BoxPositionCalculator.hxx"
#include "TilePopperSystem.hxx"
#include "ResourceUtil.hxx"
#include "AnimationSet.hxx"

void SmokeAdder::add(entityx::EntityManager &entities, const DrawPosition &drawPosition) const {
    ResourceUtil util;
    entityx::Entity smokeEntity = entities.create();
    AnimationSet animations;
    animations.setPassInterval(50);
    animations.setOneShot(true);

    for (int i=0; i<util.getSmokeSize(); i++)
    animations.addSprite(util.getSmokeNew(i), Scale(0.3));

    /*
    animations.addSprite(util.getRandomSmoke(), Scale(0.29));
    animations.addSprite(util.getRandomSmoke(), Scale(0.32));
    animations.addSprite(util.getRandomSmoke(), Scale(0.25));
    animations.addSprite(util.getRandomSmoke(), Scale(0.26));
    animations.addSprite(util.getRandomSmoke(), Scale(0.27));
    animations.addSprite(util.getRandomSmoke(), Scale(0.22));
    animations.addSprite(util.getRandomSmoke(), Scale(0.18));
    animations.addSprite(util.getRandomSmoke(), Scale(0.14));
    animations.addSprite(util.getRandomSmoke(), Scale(0.06));
    animations.addSprite(util.getRandomSmoke(), Scale(0.04));
    animations.addSprite(util.getRandomSmoke(), Scale(0.02));
    animations.addSprite(util.getRandomSmoke(), Scale(0.01));
*/
    smokeEntity.assign_from_copy<AnimationSet>(animations);
    smokeEntity.assign_from_copy(drawPosition);
}