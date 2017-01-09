//
// Created by Onat Bas on 05/01/17.
//

#include <components/BackgroundComponent.hxx>
#include <view/ResourceUtil.hxx>
#include <components/Scale.hxx>
#include <systems/GameBeginZoomOut.hxx>
#include "TerrainRenderer.hxx"
#include "components/TerrainComponent.hxx"

TerrainRenderer::TerrainRenderer(EntityFactory *factory) : factory(factory) {
    ResourceUtil util;
    entityx::Entity entity = factory->entities.create();
    entity.assign<TerrainComponent>(util.getTerrainPath());
    entity.assign<GameBeginZoomOut>(500, 0.25, 0.85);
    entity.assign<Scale>(2);
}
