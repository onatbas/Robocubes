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
