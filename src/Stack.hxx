//
// Created by Onat Bas on 01/01/17.
//

#ifndef BOXESGAME_STACK_HXX
#define BOXESGAME_STACK_HXX

#include <vector>
#include "Box.hxx"

class Stack {
public:
	Box operator[](int value) const;
	int size() const;
	bool operator==(const Stack &rhs) const;
	bool operator!=(const Stack &rhs) const;

protected:
	std::vector<Box> boxes;
	friend class BoxStacker;
};

#endif //BOXESGAME_STACK_HXX
