//
// Created by Onat Bas on 01/01/17.
//

#include "Box.hxx"

bool Box::operator==(const Box &other) const {
    return (other.color == color);
}

Box::Box(Colors color) {
    this->color = color;
}

Colors Box::getColor() const {
    return color;
}
