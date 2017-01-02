//
// Created by Onat Bas on 01/01/17.
//

#ifndef BOXESGAME_HORIZONTALANDVERTICALNEIGBOURCOUNTER_HXX
#define BOXESGAME_HORIZONTALANDVERTICALNEIGBOURCOUNTER_HXX

#include <queue>
#include "HorizontalAndVerticalNeighbourCountResult.hxx"
#include "StackSet.hxx"
#include "BoxPosition.hxx"

class HorizontalAndVerticalNeigbourCounter {

public:
	HorizontalAndVerticalNeighbourCountResult count(const StackSet &set, const BoxPosition &position) const;
	bool wasProcessedBefore(const std::vector<BoxPosition> &counted, const BoxPosition &current) const;
	void addToProcessedList(std::vector<BoxPosition> &counted, const BoxPosition &current) const;
	void addNeighboursToToBeProcessed(const StackSet &set, const BoxPosition position,
										  std::queue<BoxPosition> & queue,
										  Colors originalColor) const;
	bool hasEnoughNeighbours(const StackSet &set, const BoxPosition & position,
								 Colors originalColor) const;
	bool isSameColor(Colors colors, const StackSet &set, const BoxPosition &position) const;
	bool tileExists(const StackSet &set, const BoxPosition &position) const;
	std::vector<BoxPosition> getPositions(const BoxPosition &position) const;
};

#endif //BOXESGAME_HORIZONTALANDVERTICALNEIGBOURCOUNTER_HXX
