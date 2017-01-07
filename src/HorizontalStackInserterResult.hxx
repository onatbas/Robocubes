//
// Created by Onat Bas on 07/01/17.
//

#ifndef BOXESGAME_HORIZONTALSTACKINSERTERRESULT_HXX
#define BOXESGAME_HORIZONTALSTACKINSERTERRESULT_HXX

#include <StackSet.hxx>
#include <HorizontalMovements.hxx>

class HorizontalStackInserterResult {

public:
    HorizontalStackInserterResult(StackSet set, HorizontalMovements movements);
    const StackSet &getSet() const;
    const HorizontalMovements &getMovements() const;

private:
    StackSet set;
    HorizontalMovements movements;
};

#endif //BOXESGAME_HORIZONTALSTACKINSERTERRESULT_HXX
