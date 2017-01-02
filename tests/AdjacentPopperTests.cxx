//
// Created by Onat Bas on 02/01/17.
//


#include "../src/AdjacentPopper.hxx"
#include "gtest/gtest.h"
#include "StackHelpers.hxx"

TEST(AdjacentPopperTests, shouldPopVerticals) {
    StackSet set = getStackSetByCodeList("bbb");
    AdjacentPopper popper;
    AdjacentPopperResult result = popper.pop(set, BoxPosition(0, 0));
    PoppedPositions popped = result.getPopped();
    EXPECT_EQ(popped.getSize(), set[0].size());
}

TEST(AdjacentPopperTests, shouldPopVerticalsAndHorizontals) {
    StackSet set = getStackSetByCodeList("bb bb");
    AdjacentPopper popper;
    AdjacentPopperResult result = popper.pop(set, BoxPosition(0, 0));

    EXPECT_EQ(4, result.getPopped().getSize());
}