//
// Created by Onat Bas on 02/01/17.
//

#ifndef BOXESGAME_ADJACENTPOPPER_HXX
#define BOXESGAME_ADJACENTPOPPER_HXX

#include "StackSet.hxx"
#include "AdjacentPopperResult.hxx"

class AdjacentPopper {
public:
    AdjacentPopperResult pop(const StackSet &set, const BoxPosition &position) const;
};

#endif //BOXESGAME_ADJACENTPOPPER_HXX
