//
// Created by Onat Bas on 02/01/17.
//

#ifndef BOXESGAME_TILEEXISTSCHECKER_HXX
#define BOXESGAME_TILEEXISTSCHECKER_HXX

#include "StackSet.hxx"

class TileExistsChecker {

public:
    bool tileExists(const StackSet &set, const BoxPosition &position) const;
};

#endif //BOXESGAME_TILEEXISTSCHECKER_HXX
