//
// Created by Onat Bas on 02/01/17.
//

#include <BoxPosition.hxx>
#include "PoppedPositions.hxx"

int PoppedPositions::getSize() const {
    return positions.size();
}

void PoppedPositions::popPosition(const BoxPosition &position) {
    positions.push_back(position);
}

BoxPosition PoppedPositions::operator[](int i) const {
    return positions[i];
}
