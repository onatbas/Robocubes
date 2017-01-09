//
// Created by Onat Bas on 08/01/17.
//

#include <view/WindowOpener.hxx>
#include <gtest/gtest.h>
#include <view/WindowRenamer.hxx>
#include <decorators/GameLooper.hxx>
#include <decorators/LoopTerminator.hxx>
#include <EntityFactory.hxx>
#include <systems/RenderingSystem.hxx>
#include <view/WindowDimensionGetter.hxx>
#include <systems/AnimationSubSystem.hxx>
#include <logic/StackSet.hxx>
#include "EntityFactory.hxx"
#include "delegates/PlainBackgroundMaker.hxx"
#include "delegates/LogoMaker.hxx"
#include "delegates/BackgroundBoxesMaker.hxx"
#include "systems/VelocitySystem.hxx"
#include "view/StartButtonMaker.hxx"
#include "decorators/AnyClickTracker.hxx"
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
#include "gtest/gtest.h"
#include "systems/AnimationSubSystem.hxx"
#include "systems/TilePopperSystem.hxx"
#include "systems/TileVerticalMover.hxx"
#include "systems/TileHorizontalMover.hxx"
#include "delegates/BackgroundRendererEntityFactory.hxx"
#include "view/TerrainRenderer.hxx"



TEST(MainMenuTests, shouldShowMainMenu)
{
    WindowOpener opener;
    auto window = opener.open();

    WindowRenamer renamer;
    renamer.rename(window, "Main menu: start-quit-logo and background: boxes falling");

    WindowDimensionGetter getter;
    Dimension windowDimensions = getter.getDimensionsOfWindows(window.get());

    GameLooper looper;
    LoopTerminator terminator(looper);

    EntityFactory factory(&looper);
    auto renderingSystem = std::make_shared<RenderingSystem>(&factory, window.get());
    renderingSystem->addSubSystem(std::make_shared<BackgroundRendererSubSystem>());
    renderingSystem->addSubSystem(std::make_shared<TerrainRendererSubSystem>());
    renderingSystem->addSubSystem(std::make_shared<AnimationSubSystem>());
    factory.addSystem(renderingSystem);
    factory.addSystem(std::make_shared<VelocitySystem>(true, windowDimensions));

    PlainBackgroundMaker backgroundMaker(&factory, &looper);
    TerrainRenderer terrain(&factory);
    BackgroundBoxesMaker boxMaker(&looper, &factory, windowDimensions);
    LogoMaker maker(&looper, &factory, windowDimensions);
    StartButtonMaker buttonMaker(&looper, &factory, windowDimensions);
    AnyClickTracker tracker(&looper, [&](){
        looper.exit();
    });
    looper.loop();
}