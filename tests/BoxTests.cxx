#include <iostream>
#include "../src/Box.hxx"
#include "../src/BoxStacker.hxx"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(BoxTests, boxes_have_colors) {
    Box box(GREEN);
    EXPECT_EQ(GREEN, box.getColor());
}

TEST(BoxTests, boxes_stack_vertically) {
    Box first(GREEN);
    Box second(BLUE);
    BoxStacker stacker;
    Stack boxes = stacker.stackOnTop(first, second);

    EXPECT_EQ(boxes[0], first);
    EXPECT_EQ(boxes[1], second);
}

TEST(BoxTests, multiple_boxes_stack_vertically) {
    BoxStacker stacker;
    Stack stack;
    for (int i = 0; i < 100; i++)
        stack = stacker.stackOn(stack, Box(GREEN));
    EXPECT_EQ(100, stack.size());
}

TEST(BoxTests, stacker_should_stack_in_order) {
    Box first(GREEN);
    Box second(BLUE);
    BoxStacker stacker;
    Stack boxes = stacker.stackOnTop(first, second);

    EXPECT_FALSE(boxes[1] == first);
    EXPECT_FALSE(boxes[0] == second);

}