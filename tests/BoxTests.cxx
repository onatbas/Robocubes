#include <iostream>
#include <Box.hxx>
#include <BoxStacker.hxx>

#include "Colors.hxx"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(BoxTests, boxes_have_colors)
{
	Box box(GREEN);
	EXPECT_EQ(GREEN, box.getColor());
}


TEST(BoxTests, boxes_stack_vertically)
{
	Box first(GREEN);
	Box second(BLUE);
	BoxStacker stacker;
	Stack boxes = stacker.stackOnTop(first, second);
	
	EXPECT_EQ(boxes[0], first);
	EXPECT_EQ(boxes[1], second);
}


TEST(BoxTests, stacker_should_stack_in_order)
{
	Box first(GREEN);
	Box second(BLUE);
	BoxStacker stacker;
	Stack boxes = stacker.stackOnTop(first, second);
	
	EXPECT_FALSE(boxes[1] == first);
	EXPECT_FALSE(boxes[0] == second);
}