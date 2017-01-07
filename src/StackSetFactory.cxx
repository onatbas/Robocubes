//
// Created by Onat Bas on 07/01/17.
//

#include "StackSetFactory.hxx"
#include "StackFactory.hxx"

StackSet StackSetFactory::createFrom(std::string choices, int columns, int row) const {

    StackSet set;
    StackFactory factory;
    for (int i = 0; i < columns; i++)
        set.addStack(factory.createFrom(choices, row));
    return set;
}
