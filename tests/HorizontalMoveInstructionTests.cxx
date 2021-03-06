//
// Created by Onat Bas on 02/01/17.
//


#include <logic/StackSet.hxx>
#include <logic/VerticalMover.hxx>
#include <logic/AdjacentPopper.hxx>
#include "gtest/gtest.h"
#include "StackHelpers.hxx"
#include "logic/HorizontalMover.hxx"

TEST(HorizontalInstructionsTest, shouldDoNothingIfNoStackIsNull) {
    StackSet set = getStackSetByCodeList("bgb bbbr bbbr");
    AdjacentPopper popper;
    const AdjacentPopperResult result = popper.pop(set, BoxPosition(1, 0));

    VerticalMover verticalMover;
    VerticalMovements verticalMovements = verticalMover.move(set, result);

    HorizontalMover horizontalMover;
    HorizontalMovements horizontalMovements = horizontalMover.move(set, verticalMovements);

    EXPECT_EQ(3, horizontalMovements.getMovementsSize());
}

TEST(HorizontalInstructionsTest, shouldSlideByOneIfOneColumnIsEmpty) {
    StackSet set = getStackSetByCodeList("bgb bbbb bb bbb bbbr bbbb");
    AdjacentPopper popper;
    const AdjacentPopperResult result = popper.pop(set, BoxPosition(2, 0));

    VerticalMover verticalMover;
    VerticalMovements verticalMovements = verticalMover.move(set, result);

    HorizontalMover horizontalMover;
    HorizontalMovements horizontalMovements = horizontalMover.move(set, verticalMovements);

    EXPECT_EQ(2, horizontalMovements.getMovementsSize());
    const auto secondMovement = horizontalMovements.getMovementAt(1);
    EXPECT_EQ(HorizontalMovement(4, 3), secondMovement);
}