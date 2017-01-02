//
// Created by Onat Bas on 01/01/17.
//

#include "../src/StackSet.hxx"
#include "gtest/gtest.h"
#include "../src/AdjacentNeighbourCounter.hxx"
#include "../src/BoxPosition.hxx"
#include "StackHelpers.hxx"
#include "../src/AdjacentNeighbourCountResult.hxx"

TEST(HorizontalAndVerticalNeighbourCounting, three_single_box_column_counting)
{
	AdjacentNeighbourCounter counter;
	StackSet set = get_3_stacks_one_box_each();
	AdjacentNeighbourCountResult result = counter.count(set, BoxPosition(0,0));
	
	EXPECT_EQ(3, result.getSameColorAreaCount());
	
}

TEST(HorizontalAndVerticalNeighbourCounting, four_single_box_column_counting)
{
	AdjacentNeighbourCounter counter;
	StackSet set = get_4_stacks_bbrg();
	
	AdjacentNeighbourCountResult result1 = counter.count(set, BoxPosition(0,0));
	EXPECT_EQ(2, result1.getSameColorAreaCount());
	
	AdjacentNeighbourCountResult result2 = counter.count(set, BoxPosition(3,0));
	EXPECT_EQ(1, result2.getSameColorAreaCount());
	
}

TEST(HorizontalAndVerticalNeighbourCounting, set_square_reference)
{
	AdjacentNeighbourCounter counter;
	StackSet set = getGreenSquareStackSet();
	
	AdjacentNeighbourCountResult result1 = counter.count(set, BoxPosition(0,0));
	EXPECT_EQ(8, result1.getSameColorAreaCount());
	
	AdjacentNeighbourCountResult result2 = counter.count(set, BoxPosition(1,1));
	EXPECT_EQ(1, result2.getSameColorAreaCount());
	
}


TEST(HorizontalAndVerticalNeighbourCounting, test_arbitrary)
{
	AdjacentNeighbourCounter counter;
	StackSet set = getStackSetByCodeList("bbbggggggg bgbb bbb gggbbbbbbb gbgbgbgbgb");
	
	AdjacentNeighbourCountResult result1 = counter.count(set, BoxPosition(0,0));
	EXPECT_EQ(9, result1.getSameColorAreaCount());
}


TEST(HorizontalAndVerticalNeighbourCounting, test_arbitrary_2)
{
	AdjacentNeighbourCounter counter;
	StackSet set = getStackSetByCodeList("bbbggggggg bgbbb bbbbb gggbbbbbbb gbgbgbgbgb rrrrrrrrrrrr g rrgrrr ");
	
	AdjacentNeighbourCountResult result1 = counter.count(set, BoxPosition(0,0));
	EXPECT_EQ(23, result1.getSameColorAreaCount());
	
	AdjacentNeighbourCountResult result2 = counter.count(set, BoxPosition(3,2));
	EXPECT_EQ(5, result2.getSameColorAreaCount());
	
	AdjacentNeighbourCountResult result3 = counter.count(set, BoxPosition(5,5));
	EXPECT_EQ(12, result3.getSameColorAreaCount());
	
	AdjacentNeighbourCountResult result4 = counter.count(set, BoxPosition(7,2));
	EXPECT_EQ(1, result4.getSameColorAreaCount());
	
	AdjacentNeighbourCountResult result5 = counter.count(set, BoxPosition(6,0));
	EXPECT_EQ(1, result5.getSameColorAreaCount());
}