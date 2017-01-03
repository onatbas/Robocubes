//
// Created by Onat Bas on 02/01/17.
//

#include "HorizontalMover.hxx"

const HorizontalMovements HorizontalMover::move(const StackSet &set, const VerticalMovements &verticalMovements) {
    HorizontalMovements result;
    const auto remainingStacks = verticalMovements.getStackOrdersWhichExist();
    const unsigned long size = set.getSize();
    int slideBy = 0;
    for (int i = 0; i < size; i++) {
        if (stackRemains(remainingStacks, i)) {
            result.addMovement(HorizontalMovement(i, slideBy));
        } else {
            slideBy++;
        }
    }
    return result;
}

bool HorizontalMover::stackRemains(const std::vector<StackOrder> &remainingStacks, int i) const {
    return find(remainingStacks.begin(), remainingStacks.end(), i) != remainingStacks.end();
}
