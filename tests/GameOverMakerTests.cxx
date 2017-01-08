//
// Created by Onat Bas on 08/01/17.
//


#include "gtest/gtest.h"
#include <WindowOpener.hxx>
#include <WindowRenamer.hxx>
#include <GameLooper.hxx>
#include <LoopTerminator.hxx>
#include <EntityFactory.hxx>
#include <AnimationSubSystem.hxx>
#include <WindowDimensionGetter.hxx>
#include "RenderingSystem.hxx"
#include "GameOverMaker.hxx"

TEST(GameOverMakerTests, shouldSayGameOver)
{
    WindowOpener opener;
    auto window = opener.open();

    WindowRenamer renamer;
    renamer.rename(window, "Game over should animate");

    WindowDimensionGetter getter;
    auto windowDimension = getter.getDimensionsOfWindows(window.get());

    GameLooper looper;
    LoopTerminator terminator(looper);

    EntityFactory factory(&looper);
    auto renderingSystem = std::make_shared<RenderingSystem>(&factory, window.get());
    renderingSystem->addSubSystem(std::make_shared<AnimationSubSystem>());
    factory.addSystem(renderingSystem);


    GameOverMaker gameOver(&looper, &factory, windowDimension);

    looper.sendSignal(BOXESGAME_ENDGAME, 0, nullptr);
    looper.loop();
}