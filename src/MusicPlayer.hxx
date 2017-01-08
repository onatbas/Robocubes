//
// Created by Onat Bas on 08/01/17.
//

#ifndef BOXESGAME_MUSICPLAYER_HXX
#define BOXESGAME_MUSICPLAYER_HXX

#include "EntityFactory.hxx"

class MusicPlayer {

private:
    EntityFactory *factory;
public:
    MusicPlayer(EntityFactory *factory);
};

#endif //BOXESGAME_MUSICPLAYER_HXX
