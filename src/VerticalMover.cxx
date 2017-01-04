//
// Created by Onat Bas on 02/01/17.
//

#include "VerticalMover.hxx"

VerticalMovements VerticalMover::move(const StackSet &set, const AdjacentPopperResult &result) const {
    VerticalMovements movements;
    const PoppedPositions positions = result.getPopped();
    PoppedStackList dividedIntoStacks = dividePoppedByStacks(positions);

    const int stackAmount = set.getSize();
    for (int i = 0; i < stackAmount; i++) {
        SingleStackPoppedList popped = dividedIntoStacks[i];

        Stack stack = set[i];
        int moveDown = 0;

        for (int j = 0; j < stack.size(); j++) {
            auto position = BoxPosition(i, j);
            if (notPopped(popped, position)) {
                movements.addMovement(position, moveDown);
            } else
                moveDown++;
        }

    }
    return movements;
}

bool VerticalMover::notPopped(SingleStackPoppedList &popped, const BoxPosition &position) const {
    return find(popped.begin(), popped.end(), position) == popped.end();
}

PoppedStackList VerticalMover::dividePoppedByStacks(const PoppedPositions &positions) const {
    PoppedStackList list;
    const auto size = positions.getSize();
    for (int i = 0; i < size; i++) {
        const BoxPosition position = positions[i];
        list[position.getX()].push_back(position);
    }
    return list;
}
