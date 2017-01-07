//
// Created by Onat Bas on 07/01/17.
//

#include "StackFactory.hxx"
#include "BoxStacker.hxx"
#include "CharToColorConverter.hxx"
#include <random>

Stack StackFactory::createFrom(std::string choices, int boxAmount) const {
    Stack s;
    BoxStacker stacker;

    CharToColorConverter converter;
    for (int i = 0; i < boxAmount; i++) {
        int randomIndex = (std::rand() / (float) RAND_MAX * choices.size());
        s = stacker.stackOn(s, Box(converter.convert(choices[randomIndex])));
    }
    return s;
}
