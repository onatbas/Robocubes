//
// Created by Onat Bas on 01/01/17.
//

#include "Stack.hxx"

Box Stack::operator[](int value) const {
	return boxes[value];
}

int Stack::size() const{
	return boxes.size();
}

bool Stack::operator==(const Stack &rhs) const {
	return boxes == rhs.boxes;
}

bool Stack::operator!=(const Stack &rhs) const {
	return !(rhs == *this);
}
