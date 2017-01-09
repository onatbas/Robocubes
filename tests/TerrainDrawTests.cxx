//
// Created by Onat Bas on 05/01/17.
//


#include <view/WindowOpener.hxx>
#include <decorators/GameLooper.hxx>
#include <decorators/LoopTerminator.hxx>
#include <view/WindowRenamer.hxx>
#include <logic/StackSet.hxx>
#include <view/StackSetEntityMaker.hxx>
#include <systems/ZoomOutAnimationSystem.hxx>
#include <delegates/BackgroundRendererEntityFactory.hxx>
#include "gtest/gtest.h"
#include "EntityFactory.hxx"
#include "systems/RenderingSystem.hxx"
#include "view/TerrainRenderer.hxx"
#include "StackHelpers.hxx"

TEST(TerrainDrawTests, shouldRenderTerrain)
{
    WindowOpener opener;
    auto window = opener.open();

    GameLooper looper;
    LoopTerminator terminator(looper);

    WindowRenamer renamer;
    renamer.rename(window, "The terrain and brb bbb stack should appear.");

    StackSet set = getStackSetByCodeList("rrg  gr bbggr brb bbgbr rrrgbb");

    EntityFactory factory(&looper);
    const std::shared_ptr<RenderingSystem> &renderingSystem = std::make_shared<RenderingSystem>(&factory, window.get());
    renderingSystem->addSubSystem(std::make_shared<BackgroundRendererSubSystem>());
    renderingSystem->addSubSystem(std::make_shared<TerrainRendererSubSystem>());
    renderingSystem->addSubSystem(std::make_shared<BoxRendererSubSystem>());
    factory.addSystem(renderingSystem);
    factory.addSystem(std::make_shared<ZoomOutAnimationSystem>());

    TerrainRenderer terrain(&factory);
    StackSetEntityMaker maker(&factory);
    maker.makeEntities(set);


    std::string path(MATERIALS_FOLDER);
    path.append("colored_grass.png");
    BackgroundRendererEntityFactory backgroundRenderer(path, &factory);


    looper.loop();
}