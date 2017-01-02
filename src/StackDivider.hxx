//
// Created by Onat Bas on 01/01/17.
//

#ifndef BOXESGAME_STACKDIVIDER_HXX
#define BOXESGAME_STACKDIVIDER_HXX

#include "Stack.hxx"

class StackDivider {

public:
	Stack GetUpperThan(const Stack &stack, int from);
	Stack GetLowerThan(const Stack &stack, int from);
};

#endif //BOXESGAME_STACKDIVIDER_HXX
