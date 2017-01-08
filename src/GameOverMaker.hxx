//
// Created by Onat Bas on 08/01/17.
//

#ifndef BOXESGAME_GAMEOVERMAKER_HXX
#define BOXESGAME_GAMEOVERMAKER_HXX

#include "GameLooper.hxx"
#include "EntityFactory.hxx"
#include "Dimension.hxx"

class GameOverMaker {

private:
public:
    GameOverMaker(GameLooper *looper, EntityFactory *factory, Dimension windowDimension);
private:
    GameLooper *looper;
    EntityFactory *factory;
    bool endGame;
    entityx::Entity entity;
};

#endif //BOXESGAME_GAMEOVERMAKER_HXX
