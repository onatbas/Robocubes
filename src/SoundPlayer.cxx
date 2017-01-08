//
// Created by Onat Bas on 08/01/17.
//

#include "SoundPlayer.hxx"
#include "Sound.hxx"

SoundPlayer::SoundPlayer(int event, const std::string &path, EntityFactory *factory, GameLooper *looper) : event(event),
                                                                                                           path(path),
                                                                                                           factory(factory),
                                                                                                           looper(looper) {
    looper->observe(event, 0, [=](const char *data){
        auto entity = factory->entities.create();
        entity.assign<Sound>(path);
    });
}
