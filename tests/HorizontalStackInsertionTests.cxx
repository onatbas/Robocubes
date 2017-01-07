//
// Created by Onat Bas on 07/01/17.
//

#include <StackSet.hxx>
#include <HorizontalStackInserter.hxx>
#include <HorizontalMovements.hxx>
#include "gtest/gtest.h"
#include "StackHelpers.hxx"
#include "HorizontalStackInserterResult.hxx"

TEST(HorizontalStackInsertion, shouldAddAStack)
{
    StackSet set = getStackSetByCodeList("rbr bbb");
    Stack stack = getStackByCode("rrr");

    HorizontalStackInserter inserter;
    HorizontalStackInserterResult result = inserter.insertTo(set, stack);
    StackSet updated = result.getSet();
    HorizontalMovements movements = result.getMoveme"nts();

    EXPECT_EQ(set.getSize()+1, updated.getSize());
    EXPECT_EQ(stack, updated.getStackAt(0));
    for (int i=0; i<set.getSize(); i++)
        EXPECT_EQ(updated.getStackAt(i+1), set.getStackAt(i));
}