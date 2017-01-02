//
// Created by Onat Bas on 02/01/17.
//

#ifndef BOXESGAME_HORIZONTALMOVER_HXX
#define BOXESGAME_HORIZONTALMOVER_HXX

#include <StackSet.hxx>
#include <VerticalMovements.hxx>
#include "HorizontalMovements.hxx"

class HorizontalMover {

public:
    const HorizontalMovements move(const StackSet &set, const VerticalMovements &verticalMovements);
};

#endif //BOXESGAME_HORIZONTALMOVER_HXX
