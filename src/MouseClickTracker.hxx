//
// Created by Onat Bas on 05/01/17.
//

#ifndef BOXESGAME_MOUSECLICKTRACKER_HXX
#define BOXESGAME_MOUSECLICKTRACKER_HXX

#include "GameLooper.hxx"
#include "EntityFactory.hxx"
#include "Dimension.hxx"

class MouseClickTracker {

public:
    MouseClickTracker(GameLooper *looper, EntityFactory *factory, Dimension windowDimensions);
private:
    GameLooper &looper;
};

#endif //BOXESGAME_MOUSECLICKTRACKER_HXX
