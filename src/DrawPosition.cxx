//
// Created by Onat Bas on 03/01/17.
//

#include "DrawPosition.hxx"

DrawPosition::DrawPosition(int x, int y) : Vector2D(x, y) {

}

int DrawPosition::getX() const {
    return w;
}

int DrawPosition::getY() const {
    return h;
}
