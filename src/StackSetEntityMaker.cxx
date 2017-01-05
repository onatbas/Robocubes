//
// Created by Onat Bas on 04/01/17.
//

#include "StackSetEntityMaker.hxx"
#include "Scale.hxx"
#include "GameBeginZoomOut.hxx"

void StackSetEntityMaker::makeEntities(const StackSet &set) {

    const int size = set.getSize();
    for (int i=0; i < size;i++) {
        const Stack &stack = set[i];
        const int size1 = stack.size();
        for(int j=0; j < size1; j++)
        {
            auto entity = factory->entities.create();
            entity.assign_from_copy<Box>(stack[j]);
            entity.assign_from_copy<BoxPosition>(BoxPosition(i,j));
            entity.assign<Scale>(1);
            entity.assign<GameBeginZoomOut>(500, 0.25, 0.5);
        }
    }
}

StackSetEntityMaker::StackSetEntityMaker(EntityFactory *factory) : factory(factory) {
}

