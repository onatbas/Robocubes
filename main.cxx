//
// Created by Onat Bas on 07/01/17.
//

#include <WindowOpener.hxx>
#include <GameLooper.hxx>
#include <LoopTerminator.hxx>
#include <WindowRenamer.hxx>
#include <StackSet.hxx>
#include <EntityFactory.hxx>
#include <StackSetEntityMaker.hxx>
#include <RenderingSystem.hxx>
#include <ZoomOutAnimationSystem.hxx>
#include <MouseClickTracker.hxx>
#include <WindowDimensionGetter.hxx>
#include <ResourceUtil.hxx>
#include <AdjacentNeighbourCounter.hxx>
#include <StackSetFactory.hxx>
#include <StackInsertionSystem.hxx>
#include <SoundSystem.hxx>
#include <MusicPlayer.hxx>
#include <SoundPlayer.hxx>
#include <GameConfig.hxx>
#include "gtest/gtest.h"
#include "AnimationSubSystem.hxx"
#include "TilePopperSystem.hxx"
#include "TileVerticalMover.hxx"
#include "TileHorizontalMover.hxx"
#include "BackgroundRendererEntityFactory.hxx"
#include "TerrainRenderer.hxx"
#include "EndGameSystem.hxx"
#include "VelocitySystem.hxx"
#include "GuiRenderer.hxx"
#include "FontRenderingSubSystem.hxx"
#include "GameOverMaker.hxx"
#include <ctime>
#include "GameCleaner.hxx"

void play(std::shared_ptr<Window> window);

bool reset = true;

int main(int argc, const char *argv[]) {

    WindowOpener opener;
    auto window = opener.open();

    while (reset)
    play(window);

    return 0;
}

void play(std::shared_ptr<Window> window) {
    reset = false;

    GameLooper looper;
    srand(time(0));
    EntityFactory factory(&looper);
    LoopTerminator terminator(looper);
    GameCleaner cleaner;
    ResourceUtil util;
    WindowRenamer renamer;
    StackSetFactory stackSetFactory;
    GameConfig config;
    StackSetEntityMaker maker(&factory);
    WindowDimensionGetter dimensionGetter;

    renamer.rename(window, "Robocubes");
    const Dimension windowDimensions = dimensionGetter.getDimensionsOfWindows(window.get());

    StackSet set;

    auto renderingSystem = std::make_shared<RenderingSystem>(&factory, window.get());
    renderingSystem->addSubSystem(std::make_shared<BackgroundRendererSubSystem>());
    renderingSystem->addSubSystem(std::make_shared<TerrainRendererSubSystem>());
    renderingSystem->addSubSystem(std::make_shared<BoxRendererSubSystem>());
    renderingSystem->addSubSystem(std::make_shared<AnimationSubSystem>());
    renderingSystem->addSubSystem(std::make_shared<FontRenderingSubSystem>());

    factory.addSystem(renderingSystem);
    factory.addSystem(std::make_shared<ZoomOutAnimationSystem>());
    factory.addSystem(std::make_shared<TileVerticalMover>(set, looper));
    factory.addSystem(std::make_shared<TileHorizontalMover>(set, looper));
    factory.addSystem(std::make_shared<TilePopperSystem>(&set, window.get(), &looper));
    factory.addSystem(std::make_shared<StackInsertionSystem>(set, looper, 4));
    factory.addSystem(std::make_shared<MouseClickTracker>(&looper, &factory, windowDimensions));
    factory.addSystem(std::make_shared<EndGameSystem>(config.getEndColumn(), windowDimensions, &looper, &set));
    factory.addSystem(std::make_shared<VelocitySystem>(false, windowDimensions));
    factory.addSystem(std::make_shared<SoundSystem>());
    factory.addSystem(std::make_shared<GuiRenderer>(&factory, windowDimensions, &looper));

    MusicPlayer player(&factory);
    SoundPlayer(BOXESEVENT_BOX_CLICKED, util.getClickedSound(), &factory, &looper);
    GameOverMaker gameOver(&looper, &factory, windowDimensions);

    cleaner.clean(&factory);
    set = stackSetFactory.createFrom(config.getChoices(), 5, 6);
    maker.makeEntities(set);
    BackgroundRendererEntityFactory renderer( util.getBackgroundPath(), &factory);
    TerrainRenderer terrain(&factory);

    looper.observe(BOXESGAME_RESET_REQUEST, 0, [&](const char *data){
        reset = true;
        looper.exit();
    });
    looper.loop();
}
