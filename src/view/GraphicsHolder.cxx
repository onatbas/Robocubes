//
// Created by Onat Bas on 08/01/17.
//

#include "GraphicsHolder.hxx"
#include <random>

GraphicsHolder::GraphicsHolder() {

}

GraphicsHolder::GraphicsHolder(bool index)
        : index(index) {
}

bool GraphicsHolder::getGraphics() {
    if (std::rand() < (float)RAND_MAX / 200)
        index = !index;
    return index;

}
