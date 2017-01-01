//
// Created by Onat Bas on 01/01/17.
//

#include <BoxStacker.hxx>
#include "StackDivider.hxx"

Stack StackDivider::GetLowerThan(const Stack &stack, int from) {
	Stack result;
	BoxStacker stacker;
	for (int i=0; i<=from; i++)
		result = stacker.stackOn(result, stack[i]);
	return result;
}

Stack StackDivider::GetUpperThan(const Stack &stack, int from) {
	Stack result;
	BoxStacker stacker;
	for (int i=from; i< stack.size(); i++)
		result = stacker.stackOn(result, stack[i]);
	return result;
}