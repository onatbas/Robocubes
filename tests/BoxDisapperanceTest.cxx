//
// Created by Onat Bas on 01/01/17.
//


#include <gtest/gtest.h>
#include "../src/BoxStacker.hxx"
#include "../src/StackPopper.hxx"
#include "StackHelpers.hxx"

TEST(BoxPopperTests, single_column_all_should_pop) {
    Stack stack = getallGreenStack();
    StackPopper popper;
    StackPopResult result = popper.popOnStack(stack, 0);
    EXPECT_EQ(0, result.stacks.size());
}

TEST(BoxPopperTests, single_column_none_should_pop) {
    Stack stack = getBlueGreenBlueStack();
    StackPopper popper;
    StackPopResult result = popper.popOnStack(stack, 0);
    EXPECT_EQ(3, result.stacks[0].size());
}

TEST(BoxPopperTests, single_column_only_two_should_pop) {
    Stack stack = getBlueBlueGreenBlueStack();
    StackPopper popper;
    StackPopResult result = popper.popOnStack(stack, 0);
    EXPECT_EQ(2, result.stacks[0].size());
}

TEST(BoxPopperTests, columns_should_be_correctly_divided) {
    Stack stack = get_3_Blue_5_Green_3_Blue_Stack();
    StackPopper popper;
    StackPopResult result1 = popper.popOnStack(stack, 0);
    EXPECT_EQ(1, result1.stacks.size());
    EXPECT_EQ(8, result1.stacks[0].size());

    StackPopResult result2 = popper.popOnStack(stack, 5);
    EXPECT_EQ(2, result2.stacks.size());
    EXPECT_EQ(3, result2.stacks[0].size());
    EXPECT_EQ(3, result2.stacks[1].size());

    StackPopResult result3 = popper.popOnStack(stack, 8);
    EXPECT_EQ(1, result3.stacks.size());
    EXPECT_EQ(8, result3.stacks[0].size());
}

TEST(BoxPopperTests, two_boxes_should_not_pop) {
    BoxStacker stacker;
    Stack s = stacker.stackOnTop(Box(GREEN), Box(RED));

    StackPopper popper;
    StackPopResult result1 = popper.popOnStack(s, 0);
    EXPECT_EQ(1, result1.stacks.size());
    EXPECT_EQ(result1.stacks[0], s);

}


