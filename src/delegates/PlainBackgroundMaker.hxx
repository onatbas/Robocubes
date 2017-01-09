//
// Created by Onat Bas on 08/01/17.
//

#ifndef BOXESGAME_PLAINBACKGROUNDMAKER_HXX
#define BOXESGAME_PLAINBACKGROUNDMAKER_HXX

#include "EntityFactory.hxx"

class PlainBackgroundMaker {

public:
    PlainBackgroundMaker(EntityFactory *factory, GameLooper *looper);
private:
    EntityFactory *factory;
};

#endif //BOXESGAME_PLAINBACKGROUNDMAKER_HXX
