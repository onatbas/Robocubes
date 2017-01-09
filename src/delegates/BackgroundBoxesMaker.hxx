//
// Created by Onat Bas on 08/01/17.
//

#ifndef BOXESGAME_BACKGROUNDBOXESMAKER_HXX
#define BOXESGAME_BACKGROUNDBOXESMAKER_HXX

#include "logic/Box.hxx"
#include "GameLooper.hxx"
#include "EntityFactory.hxx"
#include "components/Dimension.hxx"

class BackgroundBoxesMaker {

public:
    BackgroundBoxesMaker(GameLooper *pLooper, EntityFactory *pFactory, Dimension dimension);

private:
    Box randomBox() const;
    float randomRatio() const;

};
#endif //BOXESGAME_BACKGROUNDBOXESMAKER_HXX
