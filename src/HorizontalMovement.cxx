//
// Created by Onat Bas on 02/01/17.
//

#include "HorizontalMovement.hxx"

HorizontalMovement::HorizontalMovement(int stackOrder, int slideBy) : slideBy(slideBy),
                                                                      stackOrder(stackOrder) {
}

int HorizontalMovement::getSlideBy() const {
    return slideBy;
}

int HorizontalMovement::getStackOrder() const {
    return stackOrder;
}

bool HorizontalMovement::operator==(const HorizontalMovement &rhs) const {
    return slideBy == rhs.slideBy && stackOrder == rhs.stackOrder;
}

bool HorizontalMovement::operator!=(const HorizontalMovement &rhs) const {
    return !(rhs == *this);
}

bool HorizontalMovement::operator<(const HorizontalMovement &rhs) const {
    if (slideBy < rhs.slideBy)
        return true;
    if (rhs.slideBy < slideBy)
        return false;
    return stackOrder < rhs.stackOrder;
}

bool HorizontalMovement::operator>(const HorizontalMovement &rhs) const {
    return rhs < *this;
}

bool HorizontalMovement::operator<=(const HorizontalMovement &rhs) const {
    return !(rhs < *this);
}

bool HorizontalMovement::operator>=(const HorizontalMovement &rhs) const {
    return !(*this < rhs);
}

HorizontalMovement::HorizontalMovement() {
}
