//
// Created by Onat Bas on 08/01/17.
//

#ifndef BOXESGAME_SOUNDPLAYER_HXX
#define BOXESGAME_SOUNDPLAYER_HXX

#include <string>
#include "EntityFactory.hxx"
#include "decorators/GameLooper.hxx"

class SoundPlayer {
public:
    SoundPlayer(int event, const std::string &path, EntityFactory *factory, GameLooper *looper);
private:
    int event;
    std::string path;
    EntityFactory *factory;
    GameLooper *looper;

};

#endif //BOXESGAME_SOUNDPLAYER_HXX
