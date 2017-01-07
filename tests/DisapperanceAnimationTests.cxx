//
// Created by Onat Bas on 06/01/17.
//


#include <WindowOpener.hxx>
#include <GameLooper.hxx>
#include <LoopTerminator.hxx>
#include <WindowRenamer.hxx>
#include <StackSet.hxx>
#include <EntityFactory.hxx>
#include <StackSetEntityMaker.hxx>
#include <RenderingSystem.hxx>
#include <ZoomOutAnimationSystem.hxx>
#include <MouseClickTracker.hxx>
#include <WindowDimensionGetter.hxx>
#include <ResourceUtil.hxx>
#include <BoxPositionCalculator.hxx>
#include <AdjacentNeighbourCounter.hxx>
#include "gtest/gtest.h"
#include "StackHelpers.hxx"
#include "MouseClicked.hxx"
#include "Window.hxx"
#include "AnimationSet.hxx"
#include "AnimationSubSystem.hxx"
#include "AdjacentNeighbourCounter.hxx"
#include "TilePopperSystem.hxx"

class AnimateSmokeOnClick : public GameSystem<AnimateSmokeOnClick>
{
public:

public:
    virtual void
    update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) override {
        entities.each<MouseClicked, Box>([&](entityx::Entity entity, MouseClicked &clicked, Box &box){
            BoxPositionCalculator calculator;
            AdjacentNeighbourCounter counter;
            WindowDimensionGetter getter;
            BoxDrawingConfiguration configuration;
            ResourceUtil util;


            const Dimension &windowDimensions = getter.getDimensionsOfWindows(window.get());
            const Scale boxScale = configuration.getBoxFinalScale();

            std::vector<BoxPosition> positions;
            {
                BoxPosition boxPosition = clicked.getPosition();
                AdjacentNeighbourCountResult result = counter.count(set, boxPosition);

                const int size = result.getSameColorAreaCount();
                for (int i=0; i < size; i++)
                    positions.push_back(result.getNeighbourAt(i));
            }



        });
    }

    AnimateSmokeOnClick(std::shared_ptr<Window> window, StackSet &set) : window(window), set(set) {}

private:
    std::shared_ptr<Window> window;
    StackSet &set;
};

TEST(DisapperanceAnimationTest, shouldAnimateSmokeOnClick)
{
    WindowOpener opener;
    auto window = opener.open();
    WindowRenamer renamer;
    renamer.rename(window, "Stacks should animate smoke on click and their neighbours, and they disappear.");

    StackSet set = getStackSetByCodeList("brb ggg bbbbrggbbgr gbgrbgbb gbgbrb bgbggbgrrrrb g g gbgbg ");

    GameLooper looper;
    LoopTerminator terminator(looper);

    EntityFactory factory(&looper);
    auto renderingSystem = std::make_shared<RenderingSystem>(&factory, window.get());
    renderingSystem->addSubSystem(std::make_shared<BoxRendererSubSystem>());
    renderingSystem->addSubSystem(std::make_shared<AnimationSubSystem>());
    factory.addSystem(renderingSystem);
    factory.addSystem(std::make_shared<ZoomOutAnimationSystem>());
   // factory.addSystem(std::make_shared<AnimateSmokeOnClick>(window, set));
    factory.addSystem(std::make_shared<TilePopperSystem>(&set, window.get(), &looper));
    StackSetEntityMaker maker(&factory);
    maker.makeEntities(set);

    WindowDimensionGetter dimensionGetter;
    const Dimension &windowDimensions = dimensionGetter.getDimensionsOfWindows(window.get());
    factory.addSystem(std::make_shared<MouseClickTracker>(&looper, &factory, windowDimensions));

    looper.loop();
}