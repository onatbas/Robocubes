//
// Created by Onat Bas on 01/01/17.
//

#include "AdjacentNeighbourCountResult.hxx"

int AdjacentNeighbourCountResult::getSameColorAreaCount() const {
    return neighbours.size();
}

BoxPosition AdjacentNeighbourCountResult::getNeighbourAt(int i) const {
    return neighbours[i];
}

BoxPosition AdjacentNeighbourCountResult::operator[](int i) const {
    return getNeighbourAt(i);
}

