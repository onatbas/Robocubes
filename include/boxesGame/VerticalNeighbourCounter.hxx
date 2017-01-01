//
// Created by Onat Bas on 01/01/17.
//

#ifndef BOXESGAME_VERTICALNEIGHBOURCOUNTER_HXX
#define BOXESGAME_VERTICALNEIGHBOURCOUNTER_HXX

#include "Stack.hxx"
#include "VerticalNeigbourCountResult.hxx"

class VerticalNeighbourCounter {
public:
	VerticalNeigbourCountResult countNeighbours(const Stack &stack, int i) const;
	int getUpperNeighbours(const Stack &stack, int i) const;
	int getLowerNeighbours(const Stack &stack, int i) const;
};

#endif //BOXESGAME_VERTICALNEIGHBOURCOUNTER_HXX
