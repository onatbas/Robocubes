//
// Created by Onat Bas on 01/01/17.
//

#include <queue>
#include "AdjacentNeighbourCounter.hxx"

AdjacentNeighbourCountResult
HorizontalAndVerticalNeigbourCounter::count(const StackSet &set, const BoxPosition &position) const {

	std::vector<BoxPosition> counted;
	std::queue<BoxPosition> toBeCounted;
	
	int count = 1;
	counted.push_back(position);
	Colors originalColor = set[position].getColor();
	addNeighboursToToBeProcessed(set, position, toBeCounted, originalColor);
	
	while (!toBeCounted.empty())
	{
		const BoxPosition current = toBeCounted.front();
		toBeCounted.pop();
		
		if (wasProcessedBefore(counted, current))
			continue;
		
		addToProcessedList(counted, current);
		
		NeighboursInVicinityCounter counter;
		if (counter.hasEnoughNeighbours(set, current, originalColor))
		{
			count += 1;
			addNeighboursToToBeProcessed(set, current,
										 toBeCounted, originalColor);
		}
	}
	
	
	AdjacentNeighbourCountResult result(count);
	return result;
}

void HorizontalAndVerticalNeigbourCounter::addNeighboursToToBeProcessed(const StackSet &set, const BoxPosition position,
																		std::queue<BoxPosition> & queue,
																		Colors originalColor) const {
	NeighboursInVicinityCounter counter;
	SameColorChecker checker;
	auto positions = counter.getPositions(position);
	int size = positions.size();
	
	for (int i=0;i<size;i++)
		if (checker.isSameColor(originalColor, set, positions[i]))
			queue.push(positions[i]);
}

void
HorizontalAndVerticalNeigbourCounter::addToProcessedList(std::vector<BoxPosition> &counted, const BoxPosition &current) const { counted.push_back(current); }

bool HorizontalAndVerticalNeigbourCounter::wasProcessedBefore(const std::vector<BoxPosition> &counted,
															  const BoxPosition &current) const {
	return find(counted.begin(), counted.end(), current) != counted.end();
}

