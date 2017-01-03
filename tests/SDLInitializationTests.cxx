//
// Created by Onat Bas on 03/01/17.
//


#include <Box.hxx>
#include <DrawPosition.hxx>
#include "gtest/gtest.h"

#include "Window.hxx"
#include "WindowOpener.hxx"
#include "GameLooper.hxx"
#include "WindowRenamer.hxx"
#include "BoxDrawer.hxx"

TEST(SDLInitializationTests, shouldOpenWindow)
{
    WindowOpener opener;
    auto window = opener.open();
    EXPECT_TRUE(window->is_open());

    WindowRenamer renamer;
    renamer.rename(window, "A white window should open");

    GameLooper looper;
    looper.loop();
}


TEST(SDLInitializationTests, shouldRenderGreenBox)
{
    std::string path(MATERIALS_FOLDER);
    path.append("alienGreen_square.png");

    WindowOpener opener;
    auto window = opener.open();
    EXPECT_TRUE(window->is_open());

    Box box(GREEN);
    BoxDrawer renderer(path);
    renderer.draw(window.get(), box);

    WindowRenamer renamer;
    renamer.rename(window, "A green box should appear at the corner");

    GameLooper looper;
    looper.loop();
}



TEST(SDLInitializationTests, shouldRenderRedBox)
{
    std::string path(MATERIALS_FOLDER);
    path.append("alienPink_square.png");

    WindowOpener opener;
    auto window = opener.open();
    EXPECT_TRUE(window->is_open());

    Box box(RED);
    BoxDrawer renderer(path);
    renderer.drawAt(window.get(), box, DrawPosition(50, 50));

    WindowRenamer renamer;
    renamer.rename(window, "A green box should appear in the middle");

    GameLooper looper;
    looper.loop();
}

