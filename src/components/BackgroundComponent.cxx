//
// Created by Onat Bas on 04/01/17.
//

#include "BackgroundComponent.hxx"

BackgroundComponent::BackgroundComponent(const std::string &path) : path(path) {
}

const std::string &BackgroundComponent::getPath() const {
    return path;
}
