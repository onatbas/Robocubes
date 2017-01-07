//
// Created by Onat Bas on 07/01/17.
//

#ifndef BOXESGAME_HORIZONTALSTACKINSERTER_HXX
#define BOXESGAME_HORIZONTALSTACKINSERTER_HXX

#include "../tests/HorizontalStackInserterResult.hxx"
#include "StackSet.hxx"

class HorizontalStackInserter {

public:
    HorizontalStackInserterResult insertTo(StackSet &set, Stack &stack);
};

#endif //BOXESGAME_HORIZONTALSTACKINSERTER_HXX
