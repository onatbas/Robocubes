//
// Created by Onat Bas on 01/01/17.
//

#ifndef BOXESGAME_BOXSTACKER_HXX
#define BOXESGAME_BOXSTACKER_HXX

#include <memory>
#include "Box.hxx"
#include "Stack.hxx"

class BoxStacker {

public:
	Stack stackOnTop(const Box first_box, const Box second_box) const;
};

#endif //BOXESGAME_BOXSTACKER_HXX
