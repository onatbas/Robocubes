//
// Created by Onat Bas on 02/01/17.
//

#ifndef BOXESGAME_SAMECOLORCHECKER_HXX
#define BOXESGAME_SAMECOLORCHECKER_HXX

#include "StackSet.hxx"

class SameColorChecker {

public:
    bool isSameColor(Colors colors, const StackSet &set, const BoxPosition &position) const;
};

#endif //BOXESGAME_SAMECOLORCHECKER_HXX
