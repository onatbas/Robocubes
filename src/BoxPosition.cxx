//
// Created by Onat Bas on 01/01/17.
//

#include "BoxPosition.hxx"

BoxPosition::BoxPosition(int x, int y) : x(x),
                                         y(y) {
}

int BoxPosition::getX() const {
    return x;
}

bool BoxPosition::operator<(const BoxPosition &rhs) const {
    if (x < rhs.x)
        return true;
    if (rhs.x < x)
        return false;
    return y < rhs.y;
}

bool BoxPosition::operator>(const BoxPosition &rhs) const {
    return rhs < *this;
}

bool BoxPosition::operator<=(const BoxPosition &rhs) const {
    return !(rhs < *this);
}

bool BoxPosition::operator>=(const BoxPosition &rhs) const {
    return !(*this < rhs);
}

bool BoxPosition::operator==(const BoxPosition &rhs) const {
    return x == rhs.x && y == rhs.y;
}

bool BoxPosition::operator!=(const BoxPosition &rhs) const {
    return !(rhs == *this);
}

int BoxPosition::getY() const {
    return y;
}

BoxPosition BoxPosition::operator+(const BoxPosition &rhs) const {
    return BoxPosition(x + rhs.x, y + rhs.y);
}

BoxPosition::BoxPosition() :x(0), y(0){
}
