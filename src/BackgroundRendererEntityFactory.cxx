//
// Created by Onat Bas on 03/01/17.
//

#include <PNGLoader.hxx>
#include "BackgroundRendererEntityFactory.hxx"
#include "../tests/EntityFactory.hxx"
#include "BackgroundComponent.hxx"
#include "Scale.hxx"
#include "GameBeginZoomOut.hxx"
#include <PNGDrawer.hxx>
#include <WindowUpdater.hxx>
#include <DimensionCalculator.hxx>

BackgroundRendererEntityFactory::BackgroundRendererEntityFactory(const std::string &pathToPng, EntityFactory *factory) {
    auto e = factory->entities.create();
    e.assign<BackgroundComponent>(pathToPng);
    e.assign<Scale>(1);
    e.assign<GameBeginZoomOut>(500, 0.985, 0.60);
}


