//
// Created by Onat Bas on 01/01/17.
//

#include "VerticalNeighbourCounter.hxx"

VerticalNeigbourCountResult VerticalNeighbourCounter::countNeighbours(const Stack &stack, int i) const {
    if (stack.size() >= 0) {
        const auto upper = getUpperNeighbours(stack, i);
        const auto lower = getLowerNeighbours(stack, i);
        return VerticalNeigbourCountResult(upper, lower);
    } else
        return VerticalNeigbourCountResult(-1, 0);

}

int VerticalNeighbourCounter::getUpperNeighbours(const Stack &stack, int i) const {
    if (stack.size() > i + 1)
        return (stack[i].getColor() == stack[i + 1].getColor() ? 1 + getUpperNeighbours(stack, i + 1) : 0);
    else
        return 0;
}

int VerticalNeighbourCounter::getLowerNeighbours(const Stack &stack, int i) const {
    if (stack.size() > i + 1 && i >= 0)
        return (stack[i].getColor() == stack[i - 1].getColor() ? 1 + getLowerNeighbours(stack, i - 1) : 0);
    else
        return 0;
}
