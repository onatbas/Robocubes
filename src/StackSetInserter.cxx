//
// Created by Onat Bas on 07/01/17.
//

#include "StackSetInserter.hxx"

StackSetInserter::StackSetInserter(StackSet &set) : set(&set) {
}

void StackSetInserter::insert(BoxPosition position, Box box) {
    int stackOrder = position.getX();
    while(set->getSize() <= stackOrder)
        set->addStack(Stack());
    set->insert(position, box);
}

StackSet StackSetInserter::insertStackToBegin(Stack &stack) {
    StackSet updated;
    updated.addStack(stack);
    int size = set->getSize();
    for (int i=0; i < size; i++)
        updated.addStack(set->getStackAt(i) );
    return updated;
}
