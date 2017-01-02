//
// Created by Onat Bas on 02/01/17.
//

#include "../src/StackSet.hxx"
#include "../src/AdjacentPopper.hxx"
#include "../src/VerticalMover.hxx"
#include "StackHelpers.hxx"
#include "gtest/gtest.h"

TEST(VerticalMoveInstructionTests, shouldCreateEmptyStackIfAllPopped) {
    StackSet set = getStackSetByCodeList("rrr");
    AdjacentPopper popper;
    const AdjacentPopperResult popResult = popper.pop(set, BoxPosition(0, 0));

    VerticalMover mover;
    VerticalMovements movements = mover.move(set, popResult);

    EXPECT_EQ(0, movements.getStackSize());
    EXPECT_EQ(0, movements.getMoveSizeInStack(0));
}

TEST(VerticalMoveInstructionTests, shouldDetectFallingBoxes) {
    StackSet set = getStackSetByCodeList("rrbrrb rrrrrrrrrr rrrgggg");
    AdjacentPopper popper;
    const AdjacentPopperResult popResult = popper.pop(set, BoxPosition(0, 0));

    VerticalMover mover;
    VerticalMovements movements = mover.move(set, popResult);

    EXPECT_EQ(2, movements.getStackSize());

    std::vector<VerticalMovement> firstColumn = movements.getMovesInStack(0);
    std::vector<VerticalMovement> thirdColumn = movements.getMovesInStack(2);
    EXPECT_EQ(2, firstColumn.size());
    EXPECT_EQ(4, thirdColumn.size());

    EXPECT_FALSE(std::find(firstColumn.begin(), firstColumn.end(), VerticalMovement(2, 2)) == firstColumn.end());
    EXPECT_FALSE(std::find(firstColumn.begin(), firstColumn.end(), VerticalMovement(5, 4)) == firstColumn.end());
    EXPECT_FALSE(std::find(thirdColumn.begin(), thirdColumn.end(), VerticalMovement(3, 3)) == thirdColumn.end());
    EXPECT_FALSE(std::find(thirdColumn.begin(), thirdColumn.end(), VerticalMovement(4, 3)) == thirdColumn.end());
    EXPECT_FALSE(std::find(thirdColumn.begin(), thirdColumn.end(), VerticalMovement(5, 3)) == thirdColumn.end());
    EXPECT_FALSE(std::find(thirdColumn.begin(), thirdColumn.end(), VerticalMovement(6, 3)) == thirdColumn.end());

}

TEST(VerticalMoveInstructionTests, shouldDetectFallingBoxes88Pattern) {
    StackSet set = getStackSetByCodeList("rrr rbr rrr rgr rrr rrr rggr rbr");
    AdjacentPopper popper;
    const AdjacentPopperResult popResult = popper.pop(set, BoxPosition(0, 0));

    VerticalMover mover;
    VerticalMovements movements = mover.move(set, popResult);

    EXPECT_EQ(4, movements.getStackSize());
}


TEST(VerticalMoveInstructionTests, shouldProvideInformationOnMiddleStackDisappearing) {
    StackSet set = getStackSetByCodeList("rrr bbb rrr");
    AdjacentPopper popper;
    const AdjacentPopperResult popResult = popper.pop(set, BoxPosition(1,2));

    VerticalMover mover;
    VerticalMovements movements = mover.move(set, popResult);

    EXPECT_EQ(2, movements.getStackSize());
}