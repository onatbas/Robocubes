//
// Created by Onat Bas on 06/01/17.
//

#include <PNGFactory.hxx>
#include <PNGDrawer.hxx>
#include <BoxDrawingConfiguration.hxx>
#include "AnimationSubSystem.hxx"
#include "AnimationSet.hxx"

using namespace entityx;

void AnimationSubSystem::render(entityx::EntityManager &entities, Renderable &renderable, Window *window,
                                entityx::TimeDelta delta) {
    entities.each<AnimationSet, DrawPosition>([&](Entity entity, AnimationSet &set, DrawPosition &position) {
        PNGFactory factory(window);
        BoxDrawingConfiguration config;
        PNGDrawer drawer(&renderable);

        const AnimationStep step = set.getNext(delta);

        if (!step.isNextStepValid()){
            entity.remove<AnimationSet>();
        }else {
            PNG *pPNG = factory.getPNG(step.getPath());
            drawer.draw(*pPNG, position, step.getScale());
        }
    });
}
