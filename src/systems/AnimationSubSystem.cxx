//
// Created by Onat Bas on 06/01/17.
//

#include <view/PNGFactory.hxx>
#include <view/PNGDrawer.hxx>
#include <view/BoxDrawingConfiguration.hxx>
#include <view/PNGDimensionGetter.hxx>
#include "AnimationSubSystem.hxx"
#include "components/AnimationSet.hxx"

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
            PNGDimensionGetter getter;
            const Dimension pngDimensions = getter.calculate(*pPNG);
            const Dimension boxDimensions = config.getBoxDimensions();
            float s = step.getScale().scale;

            double boxFinalScale = config.getBoxFinalScale();
            const DrawPosition center = DrawPosition(position.getX() - pngDimensions.getWidth() / 2.0 * s + boxDimensions.getWidth() *
                                                                                                            boxFinalScale / 2,
                                                position.getY() - pngDimensions.getHeight() / 2.0 * s + boxDimensions.getHeight() *
                                                                                                        boxFinalScale / 2);
            drawer.draw(*pPNG, center, step.getScale());
        }
    });
}
