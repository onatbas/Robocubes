//
// Created by Onat Bas on 07/01/17.
//

#include <entityx/entityx.h>
#include <GameLooper.hxx>
#include "TileHorizontalMover.hxx"

using namespace entityx;


TileHorizontalMover::TileHorizontalMover(StackSet *set, GameLooper *looper) : set(set),
                                                                              looper(looper) {
    looper->observe(BOXESEVENT_CHECK_HORIZONTAL_SLIDE, 0, [&](const char* e){
        checkForHorizontalMovements();
    });

}

void TileHorizontalMover::checkForHorizontalMovements() {
    const int stackSize = set->getSize();
    for(int i=0; i<stackSize-1; i++){
        if (set[i].getSize() == 0)
        {
            makeHorizontalMovements();
        }
    }
}

void TileHorizontalMover::makeHorizontalMovements() {

}
