//
// Created by Onat Bas on 01/01/17.
//

#include "components/BoxPosition.hxx"
#include "StackSet.hxx"
#include "BoxStacker.hxx"

void StackSet::addStack(const Stack &v) {
    stacks.push_back(v);
}

Stack StackSet::getStackAt(int i) const {
    return stacks[i];
}

Stack StackSet::operator[](int i) const {
    return getStackAt(i);
}

int StackSet::getSize() const {
    return stacks.size();
}

Box StackSet::operator[](const BoxPosition &v) const {
    return stacks[v.getX()][v.getY()];
}

bool StackSet::operator==(const StackSet &rhs) const {
    return stacks == rhs.stacks;
}

bool StackSet::operator!=(const StackSet &rhs) const {
    return !(rhs == *this);
}

void StackSet::insert(BoxPosition &p, Box box) {
    BoxStacker stacker;
    int stackOrder = std::max(0, p.getX());
    stacks[stackOrder] = stacker.stackOn(stacks[stackOrder], box);
}