//
// Created by Onat Bas on 05/01/17.
//

#include <view/WindowOpener.hxx>
#include <decorators/GameLooper.hxx>
#include <EntityFactory.hxx>
#include <systems/RenderingSystem.hxx>
#include <decorators/LoopTerminator.hxx>
#include <delegates/BackgroundRendererEntityFactory.hxx>
#include <view/ResourceUtil.hxx>
#include <components/BoxPosition.hxx>
#include <view/WindowRenamer.hxx>
#include <logic/StackSet.hxx>
#include <view/StackSetEntityMaker.hxx>
#include <systems/ZoomOutAnimationSystem.hxx>
#include "gtest/gtest.h"
#include "decorators/MouseClickTracker.hxx"
#include "components/MouseClicked.hxx"
#include "StackHelpers.hxx"
#include "view/TerrainRenderer.hxx"
#include "delegates/BackgroundRendererEntityFactory.hxx"
#include "view/WindowDimensionGetter.hxx"

class WindowRenemeOnClick
{
public:
    WindowRenemeOnClick(std::shared_ptr<Window> window, GameLooper &looper, StackSet &set) : window(window) {
        looper.observe(BOXESEVENT_BOX_CLICKED, 0, [&](const char *data){
            BoxPosition p = *(BoxPosition *)data;

            Box box = set[p.getX()][p.getY()];

            WindowRenamer renames;

            std::string name;
            switch (box.getColor()){
                case GREEN: name = "green"; break;
                case BLUE: name = "blue"; break;
                default: name = "red"; break;
            }

            renames.rename(window, name);
        });
    }

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
    factory.addSystem(std::make_shared<ZoomOutAnimationSystem>());

    ResourceUtil util;
    BackgroundRendererEntityFactory background(util.getBackgroundPath(), &factory);

    WindowDimensionGetter windowDimensionGetter;
    const Dimension &windowDimensions = windowDimensionGetter.getDimensionsOfWindows(window.get());
    factory.addSystem(std::make_shared<MouseClickTracker>(&looper, &factory, windowDimensions));

    StackSet set = getStackSetByCodeList("brbrgb ggggbg brrrgr bbrgbr bbggrr bbrgrr");
    StackSetEntityMaker maker(&factory);
    maker.makeEntities(set);
    TerrainRenderer terrain(&factory);

    WindowRenamer renames;
    renames.rename(window, "clicking on boxes should rename the window with box's color.");

    WindowRenemeOnClick renamer(window, looper, set);
    LoopTerminator terminator(looper);
    looper.loop();
}