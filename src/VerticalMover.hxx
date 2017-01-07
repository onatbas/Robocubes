//
// Created by Onat Bas on 02/01/17.
//

#ifndef BOXESGAME_VERTICALMOVER_HXX
#define BOXESGAME_VERTICALMOVER_HXX

#include "VerticalMovements.hxx"
#include "StackSet.hxx"
#include "AdjacentPopperResult.hxx"
#include <map>

typedef std::vector<BoxPosition> SingleStackPoppedList;
typedef std::map<StackOrder, SingleStackPoppedList> PoppedStackList;

class VerticalMover {

public:
    VerticalMovements move(const StackSet &set, const AdjacentPopperResult &result) const;
    PoppedStackList dividePoppedByStacks(const PoppedPositions &positions) const;
    bool notPopped(SingleStackPoppedList &popped, const BoxPosition &position) const;
};

#endif //BOXESGAME_VERTICALMOVER_HXX
