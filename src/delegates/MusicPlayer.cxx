//
// Created by Onat Bas on 08/01/17.
//

#include "MusicPlayer.hxx"
#include "components/Music.hxx"
#include "view/ResourceUtil.hxx"

MusicPlayer::MusicPlayer(EntityFactory *factory) : factory(factory) {
    entityx::Entity entity = factory->entities.create();
    ResourceUtil util;
    entity.assign<Music>(util.getMusicPath());
}
