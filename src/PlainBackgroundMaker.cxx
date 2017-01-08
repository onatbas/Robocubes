//
// Created by Onat Bas on 08/01/17.
//

#include "PlainBackgroundMaker.hxx"
#include "BackgroundComponent.hxx"
#include "ResourceUtil.hxx"
#include "Scale.hxx"

PlainBackgroundMaker::PlainBackgroundMaker(EntityFactory *factory, GameLooper *looper)
 : factory(factory)
{
    ResourceUtil util;
    auto entity = factory->entities.create();
    entity.assign<BackgroundComponent>(util.getBackgroundPath());
    entity.assign<Scale>(1.4);
}