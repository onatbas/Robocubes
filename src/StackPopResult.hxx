//
// Created by Onat Bas on 01/01/17.
//

#ifndef BOXESGAME_STACKPOPRESULT_HXX
#define BOXESGAME_STACKPOPRESULT_HXX

#include "Stack.hxx"
class StackPopResult {
public:
	StackPopResult(const std::vector<Stack> &stacks);
	StackPopResult();
public:
	std::vector<Stack> stacks;
	
};

#endif //BOXESGAME_STACKPOPRESULT_HXX
