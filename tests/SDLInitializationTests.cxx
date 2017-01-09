//
// Created by Onat Bas on 03/01/17.
//


#include <logic/Box.hxx>
#include <components/DrawPosition.hxx>
#include <view/ResourceUtil.hxx>
#include <view/PNGLoader.hxx>
#include "gtest/gtest.h"

#include "view/Window.hxx"
#include "view/WindowOpener.hxx"
#include "decorators/GameLooper.hxx"
#include "view/WindowRenamer.hxx"
#include "view/BoxDrawer.hxx"
#include "decorators/LoopTerminator.hxx"
#include "delegates/BackgroundRendererEntityFactory.hxx"

TEST(SDLInitializationTests, shouldOpenWindow)
{
    WindowOpener opener;
    auto window = opener.open();
    EXPECT_TRUE(window->is_open());

    WindowRenamer renamer;
    renamer.rename(window, "A white window should open");

    GameLooper looper;
    LoopTerminator terminator(looper);

    looper.loop();
}


TEST(SDLInitializationTests, shouldRenderGreenBox)
{
    std::string path(MATERIALS_FOLDER);
    path.append("alienGreen_square.png");

    WindowOpener opener;
    auto window = opener.open();
    EXPECT_TRUE(window->is_open());

    ResourceUtil util;
    PNGLoader loader;
    const PNG &png = loader.load(util.getBoxPath(Box(GREEN), false), window.get());
    Box box(GREEN);
    BoxDrawer renderer(png);
    WindowRefGetter getter(window.get());
    Renderable renderable(SDL_GetWindowSurface(getter.getWindowRef()));
    renderer.draw(&renderable, box);

    WindowRenamer renamer;
    renamer.rename(window, "A green box should appear at the corner");

    GameLooper looper;
    LoopTerminator terminator(looper);


    WindowUpdater updater;
    updater.updateWindow(window.get());


    looper.loop();
}



TEST(SDLInitializationTests, shouldRenderRedBox)
{
    std::string path(MATERIALS_FOLDER);
    path.append("alienPink_square.png");

    WindowOpener opener;
    auto window = opener.open();
    WindowRefGetter getter(window.get());
    EXPECT_TRUE(window->is_open());

    Box box(RED);
    ResourceUtil util;
    PNGLoader loader;
    PNG png = loader.load(util.getBoxPath(box, false), window.get());
    BoxDrawer boxDrawer(png);

    Renderable renderable(SDL_GetWindowSurface(getter.getWindowRef()));

    boxDrawer.drawAt(&renderable, box, DrawPosition(50, 50), 1);

    WindowRenamer renamer;
    renamer.rename(window, "A green box should appear in the middle");

    GameLooper looper;
    LoopTerminator terminator(looper);

    WindowUpdater updater;
    updater.updateWindow(window.get());

    looper.loop();
}

