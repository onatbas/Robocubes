//
// Created by Onat Bas on 08/01/17.
//

#ifndef BOXESGAME_STARTBUTTONMAKER_HXX
#define BOXESGAME_STARTBUTTONMAKER_HXX

#include "EntityFactory.hxx"
#include "GameLooper.hxx"
#include "Dimension.hxx"

class StartButtonMaker {

public:
    StartButtonMaker(GameLooper *looper, EntityFactory *factory, Dimension windowDimensions);
private:
    GameLooper *looper;
    EntityFactory *factory;
};

#endif //BOXESGAME_STARTBUTTONMAKER_HXX
