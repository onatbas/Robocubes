//
// Created by Onat Bas on 01/01/17.
//

#include "VerticalNeighbourCounter.hxx"
#include "StackDivider.hxx"
#include "StackPopper.hxx"

StackPopResult StackPopper::popOnStack(Stack stack, int i) {
    VerticalNeighbourCounter counter;
    StackDivider divider;
    VerticalNeigbourCountResult result = counter.countNeighbours(stack, i);

    StackPopResult popResult;
    if (result.getSameColorAreaCount() >= 2) {
        auto upperStack = divider.GetUpperThan(stack, result.getUpperNeighbours() + i + 1);
        auto lowerStack = divider.GetLowerThan(stack, i - result.getLowerNeighbours() - 1);
        if (upperStack.size() > 0)
            popResult.stacks.push_back(upperStack);
        if (lowerStack.size() > 0)
            popResult.stacks.push_back(lowerStack);
    } else
        popResult.stacks.push_back(stack);

    return popResult;
}
