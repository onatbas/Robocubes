//
// Created by Onat Bas on 08/01/17.
//

#include <WindowOpener.hxx>
#include <gtest/gtest.h>
#include <WindowRenamer.hxx>
#include <GameLooper.hxx>
#include <LoopTerminator.hxx>
#include <EntityFactory.hxx>
#include <RenderingSystem.hxx>
#include <WindowDimensionGetter.hxx>
#include <AnimationSubSystem.hxx>
#include <StackSet.hxx>
#include "EntityFactory.hxx"
#include "PlainBackgroundMaker.hxx"
#include "LogoMaker.hxx"
#include "BackgroundBoxesMaker.hxx"
#include "VelocitySystem.hxx"
#include "StartButtonMaker.hxx"
#include "AnyClickTracker.hxx"
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
#include "gtest/gtest.h"
#include "AnimationSubSystem.hxx"
#include "TilePopperSystem.hxx"
#include "TileVerticalMover.hxx"
#include "TileHorizontalMover.hxx"
#include "BackgroundRendererEntityFactory.hxx"
#include "TerrainRenderer.hxx"



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

    EntityFactory factoryMainMenu(&looper);
    auto renderingSystem = std::make_shared<RenderingSystem>(&factoryMainMenu, window.get());
    renderingSystem->addSubSystem(std::make_shared<BackgroundRendererSubSystem>());
    renderingSystem->addSubSystem(std::make_shared<AnimationSubSystem>());
    factoryMainMenu.addSystem(renderingSystem);
    factoryMainMenu.addSystem(std::make_shared<VelocitySystem>(true, windowDimensions));

    PlainBackgroundMaker backgroundMaker(&factoryMainMenu, &looper);
    BackgroundBoxesMaker boxMaker(&looper, &factoryMainMenu, windowDimensions);
    LogoMaker maker(&looper, &factoryMainMenu, windowDimensions);
    StartButtonMaker buttonMaker(&looper, &factoryMainMenu, windowDimensions);
    AnyClickTracker tracker(&looper, [&](){

        factoryMainMenu.setActive(false);

        StackSetFactory stackSetFactory;
        StackSet set = stackSetFactory.createFrom("rgb", 10, 8);

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

        ResourceUtil util;
        std::string path = util.getBackgroundPath();

        TerrainRenderer terrain(&factory);
        BackgroundRendererEntityFactory renderer(path, &factory);




    });


    looper.loop();
}