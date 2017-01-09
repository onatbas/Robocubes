//
// Created by Onat Bas on 08/01/17.
//

#include "StartButtonMaker.hxx"

#include "components/DrawPosition.hxx"
#include "WindowRefGetter.hxx"
#include "components/AnimationSet.hxx"
#include "ResourceUtil.hxx"
#include "BoxDrawingConfiguration.hxx"



StartButtonMaker::StartButtonMaker(GameLooper *looper, EntityFactory *factory, Dimension windowDimensions) : looper(looper),
                                                                                               factory(factory) {
    auto entity = factory->entities.create();

    WindowRefGetter getter();

    BoxDrawingConfiguration config;
    Dimension boxDimensions = config.getBoxDimensions();
    double boxFinalScale = config.getBoxFinalScale();

    int shouldBeX = windowDimensions.getWidth() / 2.0;
    int shouldBeY = windowDimensions.getHeight() / 2.0 + 100;
    entity.assign<DrawPosition>(shouldBeX - boxDimensions.getWidth() * boxFinalScale / 2,
                                shouldBeY - boxDimensions.getHeight() * boxFinalScale / 2);

    ResourceUtil util;
    AnimationSet set;
    set.setOneShot(false);
    set.setPassInterval(30);
    const std::string logoPath = util.getStartPath();
    set.addSprite(logoPath, 0.5 * 0.565);
    set.addSprite(logoPath, 0.5 * 0.575);
    set.addSprite(logoPath, 0.5 *  0.6);
    set.addSprite(logoPath, 0.5 *  0.575);
    set.addSprite(logoPath, 0.5 * 0.55);
    set.addSprite(logoPath, 0.5 * 0.525);
    set.addSprite(logoPath, 0.5 * 0.5);
    set.addSprite(logoPath, 0.5 * 0.5125);
    set.addSprite(logoPath, 0.5 * 0.525);
    set.addSprite(logoPath, 0.5 * 0.5375);
    set.addSprite(logoPath, 0.5 * 0.55);

    entity.assign_from_copy(set);

}
