//
// Created by Onat Bas on 07/01/17.
//

#include "GameConfig.hxx"

std::string GameConfig::getChoices() const {
    return "rgby";
}

int GameConfig::getRowCount() const {
    return 8;
}

int GameConfig::getEndColumn() const {
    return 6;
}
