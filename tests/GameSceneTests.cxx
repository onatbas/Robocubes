//
// Created by Onat Bas on 03/01/17.
//


#include <WindowOpener.hxx>
#include "gtest/gtest.h"
#include "BackgroundRenderer.hxx"
#include <string>
#include <GameLooper.hxx>
#include "LoopTerminator.hxx"

TEST(GameSceneTests, shouldDisplayBackground)
{
    GameLooper looper;


    WindowOpener opener;
    const std::shared_ptr<Window> &window = opener.open();


    std::string path(MATERIALS_FOLDER);
    path.append("colored_grass.png");

    // Decorators
    LoopTerminator terminator(looper);
    BackgroundRenderer renderer(path, window, looper);

    looper.loop();
}