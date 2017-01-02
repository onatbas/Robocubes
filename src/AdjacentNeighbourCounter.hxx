//
// Created by Onat Bas on 01/01/17.
//

#ifndef BOXESGAME_HORIZONTALANDVERTICALNEIGBOURCOUNTER_HXX
#define BOXESGAME_HORIZONTALANDVERTICALNEIGBOURCOUNTER_HXX

#include <queue>
#include "AdjacentNeighbourCountResult.hxx"
#include "StackSet.hxx"
#include "BoxPosition.hxx"
#include "TileExistsChecker.hxx"
#include "SameColorChecker.hxx"
#include "NeighboursInVicinityCounter.hxx"

class AdjacentNeighbourCounter {

public:
    AdjacentNeighbourCountResult count(const StackSet &set, const BoxPosition &position) const;
    bool wasProcessedBefore(const std::vector<BoxPosition> &counted, const BoxPosition &current) const;
    void addToProcessedList(std::vector<BoxPosition> &counted, const BoxPosition &current) const;
    void addNeighboursToToBeProcessed(const StackSet &set, const BoxPosition position, std::queue<BoxPosition> &queue,
                                      Colors originalColor) const;
};

#endif //BOXESGAME_HORIZONTALANDVERTICALNEIGBOURCOUNTER_HXX
