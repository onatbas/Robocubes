//
// Created by Onat Bas on 01/01/17.
//

#include "BoxStacker.hxx"

Stack BoxStacker::stackOnTop(const Box first_box, const Box second_box) const {
	Stack s;
	s.boxes.push_back(first_box);
	s.boxes.push_back(second_box);
	return s;
}

Stack BoxStacker::stackOn(const Stack stack, Box box) {
	Stack nStack = stack;
	nStack.boxes.push_back(box);
	return nStack;
}
