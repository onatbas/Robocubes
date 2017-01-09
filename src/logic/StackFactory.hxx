//
// Created by Onat Bas on 07/01/17.
//

#ifndef BOXESGAME_STACKFACTORY_HXX
#define BOXESGAME_STACKFACTORY_HXX

#include "Stack.hxx"
#include <string>

class StackFactory {

public:
    Stack createFrom(std::string choices, int boxAmount) const;
};

#endif //BOXESGAME_STACKFACTORY_HXX
