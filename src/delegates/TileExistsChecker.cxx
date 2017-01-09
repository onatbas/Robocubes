//
// Created by Onat Bas on 02/01/17.
//

#include "logic/AdjacentNeighbourCounter.hxx"

bool TileExistsChecker::tileExists(const StackSet &set, const BoxPosition &position) const {
    if (set.getSize() > position.getX() && position.getX() >= 0) {
        Stack s = set[position.getX()];
        if (s.size() > position.getY() && position.getY() >= 0)
            return true;
    }
    return false;
}