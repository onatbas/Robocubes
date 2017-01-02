//
// Created by Onat Bas on 02/01/17.
//

#ifndef BOXESGAME_NEIGHBOURSINVICINITYCOUNTER_HXX
#define BOXESGAME_NEIGHBOURSINVICINITYCOUNTER_HXX

#include "StackSet.hxx"

class NeighboursInVicinityCounter {

public:
	std::vector<BoxPosition> getPositions(const BoxPosition &position) const;
	bool hasEnoughNeighbours(const StackSet &set, const BoxPosition & position,
							 Colors originalColor) const;
};

#endif //BOXESGAME_NEIGHBOURSINVICINITYCOUNTER_HXX
