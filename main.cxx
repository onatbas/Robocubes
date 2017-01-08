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

int main(int argc, const char *argv[]) {
    WindowOpener opener;
    auto window = opener.open();
    WindowRenamer renamer;
    renamer.rename(window, "Stacks should slide left if columns are emptied.");

    StackSetFactory stackSetFactory;
    GameConfig config;
    StackSet set = stackSetFactory.createFrom(config.getChoices(), 5, 3);

    GameLooper looper;
    LoopTerminator terminator(looper);
    EntityFactory factory(&looper);
    StackSetEntityMaker maker(&factory);
    WindowDimensionGetter dimensionGetter;
    const Dimension &windowDimensions = dimensionGetter.getDimensionsOfWindows(window.get());

    maker.makeEntities(set);
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



    ResourceUtil util;
    std::string path = util.getBackgroundPath();

    TerrainRenderer terrain(&factory);
    BackgroundRendererEntityFactory renderer(path, &factory);

    MusicPlayer player(&factory);
    SoundPlayer(BOXESEVENT_BOX_CLICKED, util.getClickedSound(), &factory, &looper);

    looper.loop();
    return 0;
}
