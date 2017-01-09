//
// Created by Onat Bas on 01/01/17.
//

#include "logic/VerticalNeighbourCounter.hxx"
#include "gtest/gtest.h"
#include "StackHelpers.hxx"

TEST(NeighbourCountingTests, should_count_vertically) {
    Stack s = getBlueGreenBlueStack();
    VerticalNeighbourCounter counter;
    VerticalNeigbourCountResult result = counter.countNeighbours(s, 0);
    EXPECT_EQ(1, result.getSameColorAreaCount());

}

TEST(NeighbourCountingTests, should_count_vertically_two) {
    Stack s = getBlueBlueGreenBlueStack();
    VerticalNeighbourCounter counter;

    EXPECT_EQ(2, counter.countNeighbours(s, 0).getSameColorAreaCount());
    EXPECT_EQ(2, counter.countNeighbours(s, 1).getSameColorAreaCount());
    EXPECT_EQ(1, counter.countNeighbours(s, 2).getSameColorAreaCount());
    EXPECT_EQ(1, counter.countNeighbours(s, 3).getSameColorAreaCount());

}