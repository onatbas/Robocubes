//
// Created by Onat Bas on 06/01/17.
//

#include "Offset.hxx"

Offset::Offset(int x, int y) : x(x),
                               y(y) {
}

Offset::Offset() : x(0), y(0){
}

int Offset::getX() const {
    return x;
}

void Offset::setX(int x) {
    Offset::x = x;
}

int Offset::getY() const {
    return y;
}

void Offset::setY(int y) {
    Offset::y = y;
}
