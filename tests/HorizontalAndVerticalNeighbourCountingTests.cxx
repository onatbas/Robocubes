//
// Created by Onat Bas on 01/01/17.
//

#include <StackSet.hxx>
#include "gtest/gtest.h"
#include "HorizontalAndVerticalNeigbourCounter.hxx"
#include "BoxPosition.hxx"
#include "StackHelpers.hxx"
#include "HorizontalAndVerticalNeighbourCountResult.hxx"

TEST(HorizontalAndVerticalNeighbourCounting, three_single_box_column_counting)
{
	HorizontalAndVerticalNeigbourCounter counter;
	StackSet set = get_3_stacks_one_box_each();
	HorizontalAndVerticalNeighbourCountResult result = counter.count(set, BoxPosition(0,0));
	
	EXPECT_EQ(1, result.getSameColorAreaCount());
	
}

TEST(HorizontalAndVerticalNeighbourCounting, four_single_box_column_counting)
{
	HorizontalAndVerticalNeigbourCounter counter;
	StackSet set = get_4_stacks_bbrg();
	
	HorizontalAndVerticalNeighbourCountResult result1 = counter.count(set, BoxPosition(0,0));
	EXPECT_EQ(2, result1.getSameColorAreaCount());
	
	HorizontalAndVerticalNeighbourCountResult result2 = counter.count(set, BoxPosition(3,0));
	EXPECT_EQ(1, result2.getSameColorAreaCount());
	
}