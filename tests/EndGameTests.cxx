//
// Created by Onat Bas on 08/01/17.
//

#include <gtest/gtest.h>
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
#include <logic/AdjacentNeighbourCounter.hxx>
#include <logic/StackSetFactory.hxx>
#include <systems/StackInsertionSystem.hxx>
#include <systems/SoundSystem.hxx>
#include <delegates/MusicPlayer.hxx>
#include <delegates/SoundPlayer.hxx>
#include <GameConfig.hxx>
#include <systems/VelocitySystem.hxx>
#include "gtest/gtest.h"
#include "systems/AnimationSubSystem.hxx"
#include "systems/TilePopperSystem.hxx"
#include "systems/TileVerticalMover.hxx"
#include "systems/TileHorizontalMover.hxx"
#include "delegates/BackgroundRendererEntityFactory.hxx"
#include "view/TerrainRenderer.hxx"
#include "StackHelpers.hxx"
#include "systems/EndGameSystem.hxx"

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
    factory.addSystem(std::make_shared<EndGameSystem>(6, windowDimensions, &looper, &set));


    ResourceUtil util;
    std::string path = util.getBackgroundPath();

    TerrainRenderer terrain(&factory);

    looper.loop();
}