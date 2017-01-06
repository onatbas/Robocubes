//
// Created by Onat Bas on 05/01/17.
//

#include <WindowOpener.hxx>
#include <GameLooper.hxx>
#include <EntityFactory.hxx>
#include <RenderingSystem.hxx>
#include <LoopTerminator.hxx>
#include <BackgroundRendererEntityFactory.hxx>
#include <ResourceUtil.hxx>
#include <BoxPosition.hxx>
#include <WindowRenamer.hxx>
#include <StackSet.hxx>
#include <StackSetEntityMaker.hxx>
#include <ZoomOutAnimationSystem.hxx>
#include "gtest/gtest.h"
#include "MouseClickTracker.hxx"
#include "MouseClicked.hxx"
#include "StackHelpers.hxx"
#include "TerrainRenderer.hxx"
#include "BackgroundRendererEntityFactory.hxx"
#include "WindowDimensionGetter.hxx"

class WindowRenemeOnClick : public GameSystem<WindowRenemeOnClick>
{
public:

public:
    virtual void
    update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) override {
        entities.each<MouseClicked, Box>([&](entityx::Entity entity, MouseClicked &clicked, Box &box){
            WindowRenamer renames;

            std::string name;
            switch (box.getColor()){
                case GREEN: name = "green"; break;
                case BLUE: name = "blue"; break;
                default: name = "red"; break;
            }

            renames.rename(window, name);

            entity.remove<MouseClicked>();
        });
    }

    WindowRenemeOnClick(std::shared_ptr<Window> window) : window(window) {}

private:
    std::shared_ptr<Window> window;
};


TEST(MouseEventTests, shouldCatchBoxColorOnClick)
{
    WindowOpener opener;
    auto window = opener.open();

    GameLooper looper;

    EntityFactory factory(&looper);
    const std::shared_ptr<RenderingSystem> &renderingSystem = std::make_shared<RenderingSystem>(&factory, window.get());
    renderingSystem->addSubSystem(std::make_shared<BackgroundRendererSubSystem>());
    renderingSystem->addSubSystem(std::make_shared<TerrainRendererSubSystem>());
    renderingSystem->addSubSystem(std::make_shared<BoxRendererSubSystem>());
    factory.addSystem(renderingSystem);
    factory.addSystem(std::make_shared<WindowRenemeOnClick>(window));
    factory.addSystem(std::make_shared<ZoomOutAnimationSystem>());

    ResourceUtil util;
    BackgroundRendererEntityFactory background(util.getBackgroundPath(), &factory);

    WindowDimensionGetter windowDimensionGetter;
    const Dimension &windowDimensions = windowDimensionGetter.getDimensionsOfWindows(window.get());
    MouseClickTracker tracker(&looper, &factory, windowDimensions);

    StackSet set = getStackSetByCodeList("brbrgb ggggbg brrrgr bbrgbr bbggrr bbrgrr");
    StackSetEntityMaker maker(&factory);
    maker.makeEntities(set);
    TerrainRenderer terrain(&factory);

    WindowRenamer renames;
    renames.rename(window, "clicking on boxes should rename the window with box's color.");

    LoopTerminator terminator(looper);
    looper.loop();
}