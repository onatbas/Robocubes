//
// Created by Onat Bas on 07/01/17.
//

#ifndef BOXESGAME_STACKSETINSERTER_HXX
#define BOXESGAME_STACKSETINSERTER_HXX

#include <StackSet.hxx>
#include <BoxStacker.hxx>

class StackSetInserter {


    StackSet *set;
public:
    StackSetInserter(StackSet &set);
    void insert(BoxPosition position, Box box);
    StackSet insertStackToBegin(Stack &stack);
};


#endif //BOXESGAME_STACKSETINSERTER_HXX
