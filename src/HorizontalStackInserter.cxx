//
// Created by Onat Bas on 07/01/17.
//

#include "HorizontalStackInserter.hxx"
#include "StackSetInserter.hxx"

HorizontalStackInserterResult HorizontalStackInserter::insertTo(StackSet &set, Stack &stack) {

    StackSetInserter inserter(set);
    StackSet updated = inserter.insertStackToBegin(stack);
    HorizontalMovements movements;
    int oldSize = set.getSize();
    for (int i=0; i < oldSize; i++)
        movements.addMovement(HorizontalMovement(i, -1));

    return HorizontalStackInserterResult(updated, movements);
}
