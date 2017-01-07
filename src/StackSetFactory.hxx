//
// Created by Onat Bas on 07/01/17.
//

#ifndef BOXESGAME_STACKSETFACTORY_HXX
#define BOXESGAME_STACKSETFACTORY_HXX

#include "StackSet.hxx"
#include <string>

class StackSetFactory {
public:
    StackSet createFrom(std::string choices, int columns, int row) const;
};

#endif //BOXESGAME_STACKSETFACTORY_HXX
