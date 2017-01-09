//
// Created by Onat Bas on 07/01/17.
//

#include <view/WindowOpener.hxx>
#include <decorators/GameLooper.hxx>
#include <decorators/LoopTerminator.hxx>
#include <view/WindowRenamer.hxx>
#include <logic/StackSet.hxx>
#include <EntityFactory.hxx>
#include <view/StackSetEntityMaker.hxx>
#include <systems/RenderingSystem.hxx>
#include <systems/ZoomOutAnimationSystem.hxx>
#include <decorators/MouseClickTracker.hxx>
#include <view/WindowDimensionGetter.hxx>
#include <view/ResourceUtil.hxx>
#include <logic/AdjacentNeighbourCounter.hxx>
#include <logic/StackSetFactory.hxx>
#include <systems/StackInsertionSystem.hxx>
#include <systems/SoundSystem.hxx>
#include <delegates/MusicPlayer.hxx>
#include <delegates/SoundPlayer.hxx>
#include <GameConfig.hxx>
#include "gtest/gtest.h"
#include "systems/AnimationSubSystem.hxx"
#include "systems/TilePopperSystem.hxx"
#include "systems/TileVerticalMover.hxx"
#include "systems/TileHorizontalMover.hxx"
#include "delegates/BackgroundRendererEntityFactory.hxx"
#include "view/TerrainRenderer.hxx"
#include "systems/EndGameSystem.hxx"
#include "systems/VelocitySystem.hxx"
#include "systems/GuiRenderer.hxx"
#include "systems/FontRenderingSubSystem.hxx"
#include "view/GameOverMaker.hxx"
#include <ctime>
#include "delegates/GameCleaner.hxx"
#include "delegates/PlainBackgroundMaker.hxx"
#include "view/StartButtonMaker.hxx"
#include "delegates/LogoMaker.hxx"
#include "decorators/AnyClickTracker.hxx"
#include "delegates/BackgroundBoxesMaker.hxx"

void play(std::shared_ptr<Window> window);
void mainMenu(std::shared_ptr<Window> window);

bool reset = true;

int main(int argc, const char *argv[]) {

    WindowOpener opener;
    auto window = opener.open();

    WindowRenamer renamer;
    renamer.rename(window, "Robocubes");

    mainMenu(window);

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
    StackSetFactory stackSetFactory;
    GameConfig config;
    StackSetEntityMaker maker(&factory);
    WindowDimensionGetter dimensionGetter;

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


void mainMenu(std::shared_ptr<Window> window)
{
    WindowDimensionGetter getter;
    Dimension windowDimensions = getter.getDimensionsOfWindows(window.get());

    GameLooper looper;
    LoopTerminator terminator(looper);

    EntityFactory factory(&looper);
    auto renderingSystem = std::make_shared<RenderingSystem>(&factory, window.get());
    renderingSystem->addSubSystem(std::make_shared<BackgroundRendererSubSystem>());
    renderingSystem->addSubSystem(std::make_shared<TerrainRendererSubSystem>());
    renderingSystem->addSubSystem(std::make_shared<AnimationSubSystem>());
    factory.addSystem(renderingSystem);
    factory.addSystem(std::make_shared<VelocitySystem>(true, windowDimensions));

    PlainBackgroundMaker backgroundMaker(&factory, &looper);
    TerrainRenderer terrain(&factory);
    BackgroundBoxesMaker boxMaker(&looper, &factory, windowDimensions);
    LogoMaker maker(&looper, &factory, windowDimensions);
    StartButtonMaker buttonMaker(&looper, &factory, windowDimensions);
    AnyClickTracker tracker(&looper, [&](){
        looper.exit();
    });
    looper.loop();
}