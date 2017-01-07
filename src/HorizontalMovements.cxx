//
// Created by Onat Bas on 02/01/17.
//

#include "HorizontalMovements.hxx"

int HorizontalMovements::getMovementsSize() const {
    return movements.size();
}

void HorizontalMovements::addMovement(HorizontalMovement movement) {
    movements.push_back(movement);
}

HorizontalMovement HorizontalMovements::getMovementAt(int i) const {
    return movements[i];
}

HorizontalMovement HorizontalMovements::operator[](int i) const {
    return getMovementAt(i);
}

HorizontalMovements::HorizontalMovements() {
}
