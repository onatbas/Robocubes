//
// Created by Onat Bas on 08/01/17.
//

#include "BackgroundBoxesMaker.hxx"
#include "GameLooper.hxx"
#include "EntityFactory.hxx"
#include "components/Dimension.hxx"
#include "ResourceUtil.hxx"
#include "BoxDrawingConfiguration.hxx"
#include "CharToColorConverter.hxx"
#include "GameConfig.hxx"
#include "components/DrawPosition.hxx"
#include "components/AnimationSet.hxx"
#include <random>
#include "components/Velocity.hxx"

BackgroundBoxesMaker::BackgroundBoxesMaker(GameLooper *pLooper, EntityFactory *pFactory, Dimension dimension) {
    ResourceUtil util;
    BoxDrawingConfiguration config;

    for (int i = 0; i < 15; i++) {
        auto entity = pFactory->entities.create();
        Box b = randomBox();
        entity.assign<DrawPosition>(dimension.getWidth() * randomRatio(), dimension.getHeight() * randomRatio());
        AnimationSet set;
        set.setPassInterval(60);
        set.setOneShot(false);
        set.addSprite(util.getBoxPath(b, false), config.getBoxFinalScale());
        set.addSprite(util.getBoxPath(b, true), config.getBoxFinalScale());
        entity.assign_from_copy(set);
        entity.assign<Velocity>(0, 2 + 2 * randomRatio());
    }
}


Box BackgroundBoxesMaker::randomBox() const {
    CharToColorConverter converter;
    GameConfig config;
    const std::string choices = config.getChoices();
    int randomIndex = (rand() / (float) RAND_MAX * choices.size());
    Box b = Box(converter.convert(choices[randomIndex]));
    return b;
}

float BackgroundBoxesMaker::randomRatio() const {
    return std::rand() / (float)RAND_MAX ;
}
