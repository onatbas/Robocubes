//
// Created by Onat Bas on 06/01/17.
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
#include <BoxPositionCalculator.hxx>
#include "gtest/gtest.h"
#include "StackHelpers.hxx"
#include "MouseClicked.hxx"
#include "Window.hxx"
#include "AnimationSet.hxx"

class AnimateSmokeOnClick : public GameSystem<AnimateSmokeOnClick>
{
public:

public:
    virtual void
    update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) override {
        entities.each<MouseClicked, Box>([&](entityx::Entity entity, MouseClicked &clicked, Box &box){

            entityx::Entity smokeAnimator = entities.create();
            ResourceUtil util;
            AnimationSet animations;
            animations.setPassInterval(10);
            animations.setOneShot(true);
            for (int i=0; i<10; i++)
                animations.addSprite(util.getRandomSmoke());

            BoxPositionCalculator calculator;
            const BoxPosition &boxPosition = clicked.getPosition();

            WindowDimensionGetter getter;
            const Dimension &windowDimensions = getter.getDimensionsOfWindows(window.get());

            BoxDrawingConfiguration configuration;
            const Scale boxScale = configuration.getBoxFinalScale();

            smokeAnimator.assign_from_copy<AnimationSet>(animations);
            smokeAnimator.assign_from_copy<DrawPosition>(calculator.boxToDrawing(boxPosition, windowDimensions, boxScale));

            entity.remove<MouseClicked>();
        });
    }

    AnimateSmokeOnClick(std::shared_ptr<Window> window) : window(window) {}

private:
    std::shared_ptr<Window> window;
};

TEST(DisapperanceAnimationTest, shouldAnimateSmokeOnClick)
{
    WindowOpener opener;
    auto window = opener.open();
    WindowRenamer renamer;
    renamer.rename(window, "Stacks should animate smoke on click.");

    GameLooper looper;
    LoopTerminator terminator(looper);

    EntityFactory factory(&looper);
    auto renderingSystem = std::make_shared<RenderingSystem>(&factory, window.get());
    renderingSystem->addSubSystem(std::make_shared<BoxRendererSubSystem>());
    renderingSystem->addSubSystem(std::make_shared<AnimationSubSystem>());
    factory.addSystem(renderingSystem);
    factory.addSystem(std::make_shared<ZoomOutAnimationSystem>());
    factory.addSystem(std::make_shared<AnimateSmokeOnClick>(window));
    StackSet set = getStackSetByCodeList("brb ggg");
    StackSetEntityMaker maker(&factory);
    maker.makeEntities(set);

    WindowDimensionGetter dimensionGetter;
    const Dimension &windowDimensions = dimensionGetter.getDimensionsOfWindows(window.get());
    MouseClickTracker tracker(&looper, &factory, windowDimensions);

    looper.loop();
}