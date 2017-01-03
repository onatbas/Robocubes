//
// Created by Onat Bas on 03/01/17.
//

#include "Dimension.hxx"

int Dimension::getWidth() const {
    return w;
}

int Dimension::getHeight() const {
    return h;
}

Dimension::Dimension(int x, int y) : Vector2D(x, y) {

}
