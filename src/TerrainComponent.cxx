//
// Created by Onat Bas on 05/01/17.
//

#include "TerrainComponent.hxx"

TerrainComponent::TerrainComponent(const std::string &path) : path(path) {
}

const std::string &TerrainComponent::getPath() const {
    return path;
}
