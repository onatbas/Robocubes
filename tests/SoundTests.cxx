//
// Created by Onat Bas on 08/01/17.
//


#include <WindowOpener.hxx>
#include <GameLooper.hxx>
#include <LoopTerminator.hxx>
#include <WindowRenamer.hxx>
#include <EntityFactory.hxx>
#include <SoundSystem.hxx>
#include <ResourceUtil.hxx>
#include "MusicPlayer.hxx"
#include "SoundPlayer.hxx"

#include "gtest/gtest.h"
TEST(SoundTest, shouldPlayMusic)
{

    WindowOpener opener;
    auto window = opener.open();

    WindowRenamer renamer;
    renamer.rename(window, "Should play music");


    GameLooper looper;
    LoopTerminator terminator(looper);

    EntityFactory factory(&looper);
    factory.addSystem(std::make_shared<SoundSystem>());

    MusicPlayer player(&factory);
    ResourceUtil util;
    SoundPlayer soundPlayer(SDL_MOUSEBUTTONUP, util.getSoundLevelBegin(), &factory, &looper);


    looper.loop();
}

