//
// Created by Onat Bas on 07/01/17.
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
#include "TileVerticalMover.hxx"
#include "TileHorizontalMover.hxx"

TEST(MergeBackTests, shouldMergeBack)
{
    WindowOpener opener;
    auto window = opener.open();
    WindowRenamer renamer;
    renamer.rename(window, "Stacks should slide left if columns are emptied.");

    StackSet set = getStackSetByCodeList("gggggggg gggggbggggggg gggggg bbbbbbbb rgbrgbrgb");

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
    factory.addSystem(std::make_shared<TileHorizontalMover>(set, looper));
    factory.addSystem(std::make_shared<TilePopperSystem>(&set, window.get(), &looper));

    WindowDimensionGetter dimensionGetter;
    const Dimension &windowDimensions = dimensionGetter.getDimensionsOfWindows(window.get());
    factory.addSystem(std::make_shared<MouseClickTracker>(&looper, &factory, windowDimensions));

    looper.loop();
}
