//
// Created by Onat Bas on 06/01/17.
//

#include "TilePopperSystem.hxx"
#include "AdjacentNeighbourCountResult.hxx"
#include "AdjacentNeighbourCounter.hxx"
#include "WillPop.hxx"
#include "AnimationSet.hxx"
#include "ResourceUtil.hxx"
#include "BoxDrawingConfiguration.hxx"
#include "BoxPositionCalculator.hxx"
#include "Window.hxx"
#include "WindowDimensionGetter.hxx"
#include "GameLooper.hxx"

using namespace entityx;

void TilePopperSystem::update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) {

    BoxPosition clickedPos(0,0);
    if (!clicked.getClick(clickedPos))
        return;

    markBoxesToPop(entities, clickedPos);
    makePoppedDisappear(entities);
}

void TilePopperSystem::makePoppedDisappear(EntityManager &entities) const {
    entities.each<WillPop, Box, BoxPosition>([&](Entity entity, WillPop &pop, Box &box, BoxPosition &boxPosition){
        ResourceUtil util;
        const std::string &path = util.getBoxPath(box);

        BoxDrawingConfiguration config;
        Scale baseScale = config.getBoxFinalScale();

        AnimationSet animation;
        animation.setOneShot(true);
        animation.setPassInterval(40);
        animation.addSprite(path, baseScale.scale * 1);
        animation.addSprite(path, baseScale.scale * 1.05);
        animation.addSprite(path, baseScale.scale * 1.1);
        animation.addSprite(path, baseScale.scale * 1);
        animation.addSprite(path, baseScale.scale * 0.8);
        animation.addSprite(path, baseScale.scale * 0.4);
        animation.addSprite(path, baseScale.scale * 0.1);
        animation.addSprite(path, baseScale.scale * 0.05);

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

void TilePopperSystem::markBoxesToPop(entityx::EntityManager &entities, BoxPosition clickedPos) const {

    std::vector<BoxPosition> positions = getNeighbours(clickedPos);

    entities.each<BoxPosition>([&](Entity entity, BoxPosition &position) {
        if (std::find(positions.begin(), positions.end(), position) != positions.end()) {
                entity.assign<WillPop>();
            }
    });
}

std::vector<BoxPosition> TilePopperSystem::getNeighbours(const MouseClicked &clicked) const {
    std::vector<BoxPosition> positions;
    {
        BoxPosition boxPosition = clicked.getPosition();
        AdjacentNeighbourCounter counter;
        AdjacentNeighbourCountResult result = counter.count(*set, boxPosition);

        const int size = result.getSameColorAreaCount();
        if (size == 1)
            return std::vector<BoxPosition>();
        for (int i = 0; i < size; i++)
            positions.push_back(result.getNeighbourAt(i));
    }
    return positions;
}

TilePopperSystem::TilePopperSystem(StackSet *set, Window *window, GameLooper *looper) : set(set),
                                                                                        window(window){
    looper->observe(BOXESEVENT_BOX_CLICKED, 0, [&](const char *data){
       BoxPosition clickedPosition = *(BoxPosition *)data;
        clicked = clickedPosition;
    });
}



/*                AnimationSet animations;
                animations.setPassInterval(100);
                animations.setOneShot(true);
                for (int i=0; i<5; i++)
                    animations.addSprite(util.getRandomSmoke(), Scale(0.10 * i));

                entity.assign_from_copy<AnimationSet>(animations);
                entity.assign_from_copy<DrawPosition>(calculator.boxToDrawing(data, windowDimensions, boxScale));
                    */

