//
// Created by Onat Bas on 01/01/17.
//

#include <queue>
#include "HorizontalAndVerticalNeigbourCounter.hxx"

HorizontalAndVerticalNeighbourCountResult
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
		
		if (hasEnoughNeighbours(set, current, originalColor))
		{
			count += 1;
			addNeighboursToToBeProcessed(set, current,
										 toBeCounted, originalColor);
		}
	}
	
	
	HorizontalAndVerticalNeighbourCountResult result(count);
	return result;
}

void HorizontalAndVerticalNeigbourCounter::addNeighboursToToBeProcessed(const StackSet &set, const BoxPosition position,
																		std::queue<BoxPosition> & queue,
																		Colors originalColor) const {
	
	auto positions = getPositions(position);
	int size = positions.size();
	
	for (int i=0;i<size;i++)
		if (isSameColor(originalColor, set, positions[i]))
			queue.push(positions[i]);
}

std::vector<BoxPosition> HorizontalAndVerticalNeigbourCounter::getPositions(const BoxPosition &position) const {
	std::vector<BoxPosition> positions = {
			position + BoxPosition(0,1),
			position + BoxPosition(1,0),
			position + BoxPosition(0,-1),
			position + BoxPosition(-1,0)
	};
	return positions;
}

void
HorizontalAndVerticalNeigbourCounter::addToProcessedList(std::vector<BoxPosition> &counted, const BoxPosition &current) const { counted.push_back(current); }

bool HorizontalAndVerticalNeigbourCounter::wasProcessedBefore(const std::vector<BoxPosition> &counted,
															  const BoxPosition &current) const {
	return find(counted.begin(), counted.end(), current) != counted.end();
}

bool HorizontalAndVerticalNeigbourCounter::hasEnoughNeighbours(const StackSet &set, const BoxPosition & position,
															   Colors originalColor) const {
	Box current = set[position.getX()][position.getY()];
	
	int neighbours = 0;
	auto positions = getPositions(position);
	int size = positions.size();
	for (int i=0;i<size;i++)
		neighbours += isSameColor(originalColor, set, positions[i]) ? 1 : 0;
	return neighbours > 0;
}

bool HorizontalAndVerticalNeigbourCounter::isSameColor(Colors color, const StackSet &set,
													   const BoxPosition &position) const {
	const auto exists = tileExists(set, position);
	return exists && (set[position.getX()][position.getY()].getColor() == color);
}

bool HorizontalAndVerticalNeigbourCounter::tileExists(const StackSet &set, const BoxPosition &position) const {
	if (set.getSize() > position.getX() && position.getX() >= 0)
	{
		Stack s = set[position.getX()];
		if (s.size() > position.getY() && position.getY() >= 0)
			return true;
	}
	return false;
}