//
// Created by Onat Bas on 05/01/17.
//

#include "MouseClicked.hxx"

MouseClicked::MouseClicked(const BoxPosition &position) : position(position) {
}

const BoxPosition &MouseClicked::getPosition() const {
    return position;
}
