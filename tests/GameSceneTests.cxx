//
// Created by Onat Bas on 03/01/17.
//


#include <WindowOpener.hxx>
#include "gtest/gtest.h"
#include "BackgroundRendererEntityFactory.hxx"
#include <string>
#include <GameLooper.hxx>
#include <RenderingSystem.hxx>
#include <ResourceUtil.hxx>
#include "LoopTerminator.hxx"

TEST(GameSceneTests, shouldDisplayBackground)
{
    GameLooper looper;
    WindowOpener opener;
    const std::shared_ptr<Window> &window = opener.open();

    ResourceUtil util;
    std::string path = util.getBackgroundPath();

    // Decorators
    EntityFactory factory(&looper);
    factory.addSystem(std::make_shared<RenderingSystem>(&factory, window.get()));
    LoopTerminator terminator(looper);
    BackgroundRendererEntityFactory renderer(path, &factory);

    looper.loop();
}