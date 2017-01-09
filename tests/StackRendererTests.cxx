//
// Created by Onat Bas on 04/01/17.
//

#include <logic/StackSet.hxx>
#include <decorators/GameLooper.hxx>
#include <view/WindowOpener.hxx>
#include <view/WindowRenamer.hxx>
#include "gtest/gtest.h"
#include "StackHelpers.hxx"
#include "decorators/LoopTerminator.hxx"
#include "delegates/BackgroundRendererEntityFactory.hxx"
#include "view/StackSetEntityMaker.hxx"
#include "EntityFactory.hxx"
#include "systems/RenderingSystem.hxx"
#include "systems/ZoomOutAnimationSystem.hxx"
#include <memory>

TEST(StackRendererTests, shouldDisplayStack)
{
    StackSet stack = getStackSetByCodeList("bgb rrr bgbg brbrgb brbrbrbgbbgbgb bgbgbbbrrrrgbb bgbgbbbbbr rbgbrbrrrbrgbg");
    GameLooper looper;
    WindowOpener opener;
    const std::shared_ptr<Window> &window = opener.open();

    std::string path(MATERIALS_FOLDER);
    path.append("colored_grass.png");

    // Decorators
    LoopTerminator terminator(looper);
    WindowRenamer renamer;
    renamer.rename(window, "A stack should appear, and background should zoom out.");

    //ECS Classes
    EntityFactory factory(&looper);
    BackgroundRendererEntityFactory backgroundRenderer(path, &factory);
    const std::shared_ptr<RenderingSystem> &renderingSystem = std::make_shared<RenderingSystem>(&factory, window.get());
    renderingSystem->addSubSystem(std::make_shared<BackgroundRendererSubSystem>());
    renderingSystem->addSubSystem(std::make_shared<TerrainRendererSubSystem>());
    renderingSystem->addSubSystem(std::make_shared<BoxRendererSubSystem>());
    factory.addSystem(renderingSystem);
    factory.addSystem<ZoomOutAnimationSystem>(std::make_shared<ZoomOutAnimationSystem>());
    StackSetEntityMaker maker(&factory);
    maker.makeEntities(stack);

    looper.loop();
}
