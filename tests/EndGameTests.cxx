//
// Created by Onat Bas on 08/01/17.
//

#include <gtest/gtest.h>
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
#include <AdjacentNeighbourCounter.hxx>
#include <StackSetFactory.hxx>
#include <StackInsertionSystem.hxx>
#include <SoundSystem.hxx>
#include <MusicPlayer.hxx>
#include <SoundPlayer.hxx>
#include <GameConfig.hxx>
#include <VelocitySystem.hxx>
#include "gtest/gtest.h"
#include "AnimationSubSystem.hxx"
#include "TilePopperSystem.hxx"
#include "TileVerticalMover.hxx"
#include "TileHorizontalMover.hxx"
#include "BackgroundRendererEntityFactory.hxx"
#include "TerrainRenderer.hxx"
#include "StackHelpers.hxx"
#include "EndGameSystem.hxx"

TEST(EndGameTests, shouldEndGame)
{
    WindowOpener opener;
    auto window = opener.open();
    WindowRenamer renamer;
    renamer.rename(window, "After one move, game should end, boxes should fall..");


    StackSet set = getStackSetByCodeList("ryyrrrrrrr brrrrrr gyyrrrrrrrr rrrrrrrrr gyyrrrrrrrrrr brrrrrrrrrr");

    GameLooper looper;
    LoopTerminator terminator(looper);
    EntityFactory factory(&looper);
    StackSetEntityMaker maker(&factory);
    WindowDimensionGetter dimensionGetter;
    const Dimension &windowDimensions = dimensionGetter.getDimensionsOfWindows(window.get());

    maker.makeEntities(set);
    auto renderingSystem = std::make_shared<RenderingSystem>(&factory, window.get());
    renderingSystem->addSubSystem(std::make_shared<BackgroundRendererSubSystem>());
    renderingSystem->addSubSystem(std::make_shared<TerrainRendererSubSystem>());
    renderingSystem->addSubSystem(std::make_shared<BoxRendererSubSystem>());
    renderingSystem->addSubSystem(std::make_shared<AnimationSubSystem>());

    factory.addSystem(renderingSystem);
    factory.addSystem(std::make_shared<ZoomOutAnimationSystem>());
    factory.addSystem(std::make_shared<TileVerticalMover>(set, looper));
    factory.addSystem(std::make_shared<TileHorizontalMover>(set, looper));
    factory.addSystem(std::make_shared<TilePopperSystem>(&set, window.get(), &looper));
    factory.addSystem(std::make_shared<StackInsertionSystem>(set, looper, 3));
    factory.addSystem(std::make_shared<MouseClickTracker>(&looper, &factory, windowDimensions));
    factory.addSystem(std::make_shared<SoundSystem>());
    factory.addSystem(std::make_shared<VelocitySystem>(false, windowDimensions));
    factory.addSystem(std::make_shared<EndGameSystem>(6, windowDimensions, &looper));


    ResourceUtil util;
    std::string path = util.getBackgroundPath();

    TerrainRenderer terrain(&factory);

    looper.loop();
}