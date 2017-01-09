//
// Created by Onat Bas on 08/01/17.
//

#ifndef BOXESGAME_LOGOMAKER_HXX
#define BOXESGAME_LOGOMAKER_HXX

#include "GameLooper.hxx"
#include "EntityFactory.hxx"
#include "components/Dimension.hxx"

class LogoMaker {

public:
    LogoMaker(GameLooper *looper, EntityFactory *factory, Dimension windowDimensions);
private:
    GameLooper *looper;
    EntityFactory *factory;
};

#endif //BOXESGAME_LOGOMAKER_HXX
