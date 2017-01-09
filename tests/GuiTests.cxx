//
// Created by Onat Bas on 08/01/17.
//


#include <view/WindowOpener.hxx>
#include <view/WindowRenamer.hxx>
#include <decorators/GameLooper.hxx>
#include <EntityFactory.hxx>
#include <decorators/LoopTerminator.hxx>
#include <systems/RenderingSystem.hxx>
#include <systems/AnimationSubSystem.hxx>
#include <view/WindowDimensionGetter.hxx>
#include "gtest/gtest.h"
#include "systems/GuiRenderer.hxx"
#include "systems/FontRenderingSubSystem.hxx"

TEST(GuiTests, shouldDisplayGui)
{
    WindowOpener openever;
    auto window = openever.open();

    WindowRenamer renamer;
    renamer.rename(window, "should display gui");

    WindowDimensionGetter getter;
    auto windowDimensions = getter.getDimensionsOfWindows(window.get());

    GameLooper looper;
    EntityFactory factory(&looper);
    LoopTerminator terminator(looper);

    auto renderer = std::make_shared<RenderingSystem>(&factory, window.get());
    renderer->addSubSystem(std::make_shared<AnimationSubSystem>());
    renderer->addSubSystem(std::make_shared<FontRenderingSubSystem>());
    factory.addSystem(renderer);
    factory.addSystem(std::make_shared<GuiRenderer>(&factory, windowDimensions, &looper));

    looper.loop();
}