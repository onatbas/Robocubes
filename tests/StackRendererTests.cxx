//
// Created by Onat Bas on 04/01/17.
//

#include <Stack.hxx>
#include <GameLooper.hxx>
#include <WindowOpener.hxx>
#include <WindowRenamer.hxx>
#include "gtest/gtest.h"
#include "StackHelpers.hxx"
#include "LoopTerminator.hxx"
#include "BackgroundRenderer.hxx"
#include "StackDrawer.hxx"


TEST(StackRendererTests, shouldDisplayStack)
{
    Stack stack = getStackByCode("bgb");
    GameLooper looper;
    WindowOpener opener;
    const std::shared_ptr<Window> &window = opener.open();


    std::string path(MATERIALS_FOLDER);
    path.append("colored_grass.png");

    // Decorators
    LoopTerminator terminator(looper);
    BackgroundRenderer backgroundRenderer(path, window, looper);
    WindowUpdater updater(&looper, window.get());
    WindowRenamer renamer;
    renamer.rename(window, "Should display blue green blue stack");

    StackDrawer drawer(window.get(), looper);
    drawer.draw(stack);

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