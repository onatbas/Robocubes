//
// Created by Onat Bas on 02/01/17.
//


#include <StackSet.hxx>
#include <VerticalMover.hxx>
#include <AdjacentPopper.hxx>
#include "gtest/gtest.h"
#include "StackHelpers.hxx"
#include "HorizontalMover.hxx"
#include "HorizontalMovements.hxx"

TEST(HorizontalInstructionsTest, shouldDoNothingIfNoStackIsNull)
{
    StackSet set = getStackSetByCodeList("bgb bbbr bbbr");
    AdjacentPopper popper;
    const AdjacentPopperResult result = popper.pop(set, BoxPosition(1, 0));

    VerticalMover verticalMover;
    const VerticalMovements verticalMovements = verticalMover.move(set, result);

    HorizontalMover horizontalMover;
    const HorizontalMovements horizontalMovements = horizontalMover.move(set, verticalMovements);

    EXPECT_EQ(0, horizontalMovements.getMovementsSize());
}


TEST(HorizontalInstructionsTest, shouldSlideByOneIfOneColumnIsEmpty)
{
    StackSet set = getStackSetByCodeList("bgb bbbb bbbr");
    AdjacentPopper popper;
    const AdjacentPopperResult result = popper.pop(set, BoxPosition(1, 0));

    VerticalMover verticalMover;
    const VerticalMovements verticalMovements = verticalMover.move(set, result);

    HorizontalMover horizontalMover;
    const HorizontalMovements horizontalMovements = horizontalMover.move(set, verticalMovements);

    EXPECT_EQ(1, horizontalMovements.getMovementsSize());
}