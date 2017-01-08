//
// Created by Onat Bas on 08/01/17.
//

#include "GameCleaner.hxx"
#include "Box.hxx"
#include "AnimationSet.hxx"
#include "DrawPosition.hxx"
#include "BackgroundComponent.hxx"
#include "TerrainComponent.hxx"
#include "BoxPosition.hxx"

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
