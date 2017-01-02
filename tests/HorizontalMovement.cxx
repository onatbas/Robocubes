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
