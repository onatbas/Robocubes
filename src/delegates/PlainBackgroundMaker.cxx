//
// Created by Onat Bas on 08/01/17.
//

#include "PlainBackgroundMaker.hxx"
#include "components/BackgroundComponent.hxx"
#include "view/ResourceUtil.hxx"
#include "components/Scale.hxx"

PlainBackgroundMaker::PlainBackgroundMaker(EntityFactory *factory, GameLooper *looper)
 : factory(factory)
{
    ResourceUtil util;
    auto entity = factory->entities.create();
    entity.assign<BackgroundComponent>(util.getBackgroundPath());
    entity.assign<Scale>(1.4);
}