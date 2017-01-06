//
// Created by Onat Bas on 02/01/17.
//

#include "BoxPosition.hxx"
#include "VerticalMovements.hxx"

int VerticalMovements::getStackSize() const {
    return movements.size();
}

void VerticalMovements::addMovement(const BoxPosition &position, int moveDownBy) {
    movements[position.getX()].push_back(VerticalMovement(position.getY(), moveDownBy));
}

int VerticalMovements::getMoveSizeInStack(int i) {
    std::vector<VerticalMovement> type = movements[i];
    return type.size();
}

std::vector<VerticalMovement> VerticalMovements::getMovesInStack(int i) {
    return movements[i];
}

std::vector<StackOrder> VerticalMovements::getStackOrdersWhichExist()  {
    std::vector<StackOrder> orders;
    for (auto it: movements)
        orders.push_back(it.first);
    return orders;
}
