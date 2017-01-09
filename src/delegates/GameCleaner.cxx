//
// Created by Onat Bas on 08/01/17.
//

#include "GameCleaner.hxx"
#include "logic/Box.hxx"
#include "components/AnimationSet.hxx"
#include "components/DrawPosition.hxx"
#include "components/BackgroundComponent.hxx"
#include "TerrainComponent.hxx"
#include "components/BoxPosition.hxx"

using namespace entityx;
void GameCleaner::clean(EntityFactory *factorty) {

    factorty->entities.each<Box>([&](Entity entity, Box &box){
        entity.destroy();
    });
    factorty->entities.each<BoxPosition>([&](Entity entity, BoxPosition &box){
        entity.destroy();
    });

    factorty->entities.each<BackgroundComponent>([&](Entity entity, BackgroundComponent &box){
        entity.destroy();
    });

    factorty->entities.each<TerrainComponent>([&](Entity entity, TerrainComponent &box){
        entity.destroy();
    });
}
