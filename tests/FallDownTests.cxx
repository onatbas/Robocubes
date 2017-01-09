//
// Created by Onat Bas on 06/01/17.
//


#include <view/WindowOpener.hxx>
#include <decorators/GameLooper.hxx>
#include <decorators/LoopTerminator.hxx>
#include <view/WindowRenamer.hxx>
#include <logic/StackSet.hxx>
#include <EntityFactory.hxx>
#include <view/StackSetEntityMaker.hxx>
#include <systems/RenderingSystem.hxx>
#include <systems/ZoomOutAnimationSystem.hxx>
#include <decorators/MouseClickTracker.hxx>
#include <view/WindowDimensionGetter.hxx>
#include <view/ResourceUtil.hxx>
#include <view/BoxPositionCalculator.hxx>
#include <logic/AdjacentNeighbourCounter.hxx>
#include "gtest/gtest.h"
#include "StackHelpers.hxx"
#include "components/MouseClicked.hxx"
#include "view/Window.hxx"
#include "components/AnimationSet.hxx"
#include "systems/AnimationSubSystem.hxx"
#include "logic/AdjacentNeighbourCounter.hxx"
#include "systems/TilePopperSystem.hxx"
#include "systems/TileVerticalMover.hxx"
#include "systems/TileHorizontalMover.hxx"

TEST(FallDownTests, shouldFallDownWhenPopped)
{

    WindowOpener opener;
    auto window = opener.open();
    WindowRenamer renamer;
    renamer.rename(window, "Boxes should fall down upon successfull selection.");

    StackSet set = getStackSetByCodeList("rgbgbbr rrbgbbgbr rgbgbbr rrrgbbgbbr rgbgbbr rrrgbbgbr rgbgbbr rgbbgbr rrrgbgbr rgbbgbbr");

    GameLooper looper;
    LoopTerminator terminator(looper);

    EntityFactory factory(&looper);
    StackSetEntityMaker maker(&factory);
    maker.makeEntities(set);
    auto renderingSystem = std::make_shared<RenderingSystem>(&factory, window.get());
    renderingSystem->addSubSystem(std::make_shared<BoxRendererSubSystem>());
    renderingSystem->addSubSystem(std::make_shared<AnimationSubSystem>());
    factory.addSystem(renderingSystem);
    factory.addSystem(std::make_shared<ZoomOutAnimationSystem>());
    factory.addSystem(std::make_shared<TileVerticalMover>(set, looper));
    factory.addSystem(std::make_shared<TilePopperSystem>(&set, window.get(), &looper));

    WindowDimensionGetter dimensionGetter;
    const Dimension &windowDimensions = dimensionGetter.getDimensionsOfWindows(window.get());
    factory.addSystem(std::make_shared<MouseClickTracker>(&looper, &factory, windowDimensions));

    looper.loop();
}
