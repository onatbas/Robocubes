//
// Created by Onat Bas on 06/01/17.
//

#include "TilePopperSystem.hxx"
#include "AdjacentNeighbourCountResult.hxx"
#include "AdjacentNeighbourCounter.hxx"
#include "WillPop.hxx"
#include "../tests/AnimationSet.hxx"
#include "ResourceUtil.hxx"
#include "BoxDrawingConfiguration.hxx"
#include "BoxPositionCalculator.hxx"
#include "Window.hxx"
#include "WindowDimensionGetter.hxx"

using namespace entityx;

void TilePopperSystem::update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) {
    markBoxesToPop(entities);
    makePoppedDisappear(entities);
}

void TilePopperSystem::makePoppedDisappear(EntityManager &entities) const {
    entities.each<WillPop, Box, BoxPosition>([&](Entity entity, WillPop &pop, Box &box, BoxPosition &boxPosition){
        ResourceUtil util;
        const std::__1::string &path = util.getBoxPath(box);

        BoxDrawingConfiguration config;
        Scale baseScale = config.getBoxFinalScale();

        AnimationSet animation;
        animation.setOneShot(true);
        animation.setPassInterval(100);
        animation.addSprite(path, baseScale.scale * 1);
        animation.addSprite(path, baseScale.scale * 1.05);
        animation.addSprite(path, baseScale.scale * 1);
        animation.addSprite(path, baseScale.scale * 0.8);
        animation.addSprite(path, baseScale.scale * 0.4);
        animation.addSprite(path, baseScale.scale * 0.1);

        WindowDimensionGetter getter;
        const Dimension windowDimensions = getter.getDimensionsOfWindows(window);
        
        BoxPositionCalculator calculator;
        const DrawPosition drawPosition = calculator.boxToDrawing(boxPosition, windowDimensions, baseScale.scale);

        entity.assign_from_copy(animation);
        entity.assign_from_copy(drawPosition);

        entity.remove<Box>();
        entity.remove<BoxPosition>();

        SmokeAdder adder;
        adder.add(entities, drawPosition);

    });
}

void TilePopperSystem::markBoxesToPop(EntityManager &entities) const {
    entities.each<MouseClicked, Box>([&](Entity entity, MouseClicked &clicked, Box &box) {
        std::vector<BoxPosition> positions = getNeighbours(clicked);
        ComponentHandle<BoxPosition> positionHandle;

        for (Entity entity : entities.entities_with_components<BoxPosition>(positionHandle)) {
            BoxPosition position = *positionHandle.get();

            if (find(positions.begin(), positions.end(), position) != positions.end()) {
                entity.assign<WillPop>();
            }
        }

        entity.remove<MouseClicked>();
    });
}

std::vector<BoxPosition> TilePopperSystem::getNeighbours(const MouseClicked &clicked) const {
    std::__1::vector<BoxPosition> positions;
    {
        BoxPosition boxPosition = clicked.getPosition();
        AdjacentNeighbourCounter counter;
        AdjacentNeighbourCountResult result = counter.count(*set, boxPosition);

        const int size = result.getSameColorAreaCount();
        for (int i = 0; i < size; i++)
            positions.push_back(result.getNeighbourAt(i));
    }
    return positions;
}

TilePopperSystem::TilePopperSystem(StackSet *set, Window *window) : set(set),
                                                                    window(window) {
}



/*                AnimationSet animations;
                animations.setPassInterval(100);
                animations.setOneShot(true);
                for (int i=0; i<5; i++)
                    animations.addSprite(util.getRandomSmoke(), Scale(0.10 * i));

                entity.assign_from_copy<AnimationSet>(animations);
                entity.assign_from_copy<DrawPosition>(calculator.boxToDrawing(position, windowDimensions, boxScale));
                    */

