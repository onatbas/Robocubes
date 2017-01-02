//
// Created by Onat Bas on 02/01/17.
//

#include <AdjacentNeighbourCounter.hxx>
#include "AdjacentPopper.hxx"

AdjacentPopperResult AdjacentPopper::pop(const StackSet &set, const BoxPosition &position) const {

    NeighboursInVicinityCounter vicinity;
    const bool hasEnoughNeighbours = vicinity.hasEnoughNeighbours(set, position, set[position].getColor());
    if (!hasEnoughNeighbours) {
        return AdjacentPopperResult();
    }
    
    AdjacentNeighbourCounter counter;
    const auto result = counter.count(set, position);

    PoppedPositions positions;
    for (int i=0; i<result.getSameColorAreaCount(); i++)
        positions.popPosition(result[i]);

    return AdjacentPopperResult(positions);
}
