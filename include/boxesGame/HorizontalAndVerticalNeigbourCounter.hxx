//
// Created by Onat Bas on 01/01/17.
//

#ifndef BOXESGAME_HORIZONTALANDVERTICALNEIGBOURCOUNTER_HXX
#define BOXESGAME_HORIZONTALANDVERTICALNEIGBOURCOUNTER_HXX

#include "HorizontalAndVerticalNeighbourCountResult.hxx"
#include "StackSet.hxx"
#include "BoxPosition.hxx"

class HorizontalAndVerticalNeigbourCounter {

public:
	HorizontalAndVerticalNeighbourCountResult count(const StackSet &set, const BoxPosition &position) const;
};

#endif //BOXESGAME_HORIZONTALANDVERTICALNEIGBOURCOUNTER_HXX
