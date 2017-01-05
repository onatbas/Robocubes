//
// Created by Onat Bas on 04/01/17.
//

#include <StackSet.hxx>
#include <GameLooper.hxx>
#include <WindowOpener.hxx>
#include <WindowRenamer.hxx>
#include "gtest/gtest.h"
#include "StackHelpers.hxx"
#include "LoopTerminator.hxx"
#include "BackgroundRendererEntityFactory.hxx"
#include "StackSetEntityMaker.hxx"
#include "EntityFactory.hxx"
#include "RenderingSystem.hxx"
#include "ZoomOutAnimationSystem.hxx"
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
    WindowUpdater updater(&looper, window.get());
    WindowRenamer renamer;
    renamer.rename(window, "A stack should appear, and background should zoom out.");

    //ECS Classes
    EntityFactory factory(&looper);
    BackgroundRendererEntityFactory backgroundRenderer(path, &factory);
    factory.addSystem<RenderingSystem>(std::make_shared<RenderingSystem>(&factory, window.get()));
    factory.addSystem<ZoomOutAnimationSystem>(std::make_shared<ZoomOutAnimationSystem>());
    StackSetEntityMaker maker(&factory);
    maker.makeEntities(stack);

    looper.loop();
}

TEST(StackRendererTests, shouldDisplayStackCorrectColors)
{

}

TEST(StackRendererTests, shouldDisplayStackOnPlace)
{

}

TEST(StackRendererTests, shouldDisplayStackSetWithCorrectColors)
{

}

TEST(StackRendererTests, shouldDisplayStackSetOnPlace)
{

}