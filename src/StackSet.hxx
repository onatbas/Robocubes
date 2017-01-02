//
// Created by Onat Bas on 01/01/17.
//

#ifndef BOXESGAME_STACKSET_HXX
#define BOXESGAME_STACKSET_HXX

#include "Stack.hxx"
#include "BoxPosition.hxx"

class StackSet {
public:
    void addStack(const Stack &);
    Stack getStackAt(int i) const;
    Stack operator[](int i) const;
    Box operator[](const BoxPosition &) const;
    int getSize() const;
    bool operator==(const StackSet &rhs) const;
    bool operator!=(const StackSet &rhs) const;

private:
    std::vector<Stack> stacks;

};

#endif //BOXESGAME_STACKSET_HXX
