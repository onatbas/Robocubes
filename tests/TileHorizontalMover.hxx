//
// Created by Onat Bas on 07/01/17.
//

#ifndef BOXESGAME_TILEHORIZONTALMOVER_HXX
#define BOXESGAME_TILEHORIZONTALMOVER_HXX

#include <StackSet.hxx>
#include "entityx/entityx.h"
#include "GameSystem.hxx"

class TileHorizontalMover{
private:
    StackSet *set;
    GameLooper *looper;
    void checkForHorizontalMovements();
public:
    TileHorizontalMover(StackSet *set, GameLooper *looper);
    void makeHorizontalMovements();
};

#endif //BOXESGAME_TILEHORIZONTALMOVER_HXX
