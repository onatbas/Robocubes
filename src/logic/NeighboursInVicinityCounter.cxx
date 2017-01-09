//
// Created by Onat Bas on 02/01/17.
//

#include "AdjacentNeighbourCounter.hxx"

std::__1::vector<BoxPosition> NeighboursInVicinityCounter::getPositions(const BoxPosition &position) const {
    std::__1::vector<BoxPosition> positions = {position + BoxPosition(0, 1), position + BoxPosition(1, 0),
                                               position + BoxPosition(0, -1), position + BoxPosition(-1, 0)};
    return positions;
}

bool NeighboursInVicinityCounter::hasEnoughNeighbours(const StackSet &set, const BoxPosition &position,
                                                      Colors originalColor) const {
    SameColorChecker checker;
    int neighbours = 0;
    auto positions = getPositions(position);
    int size = positions.size();
    for (int i = 0; i < size; i++)
        neighbours += checker.isSameColor(originalColor, set, positions[i]) ? 1 : 0;
    return neighbours > 0;
}