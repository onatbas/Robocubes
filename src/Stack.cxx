//
// Created by Onat Bas on 01/01/17.
//

#include "Stack.hxx"

Box Stack::operator[](int value) const {
	return boxes[value];
}
