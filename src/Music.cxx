//
// Created by Onat Bas on 08/01/17.
//

#include "Music.hxx"

Music::Music(const std::string &wavPath) : wavPath(wavPath) {
}

std::string Music::getWavPath() const {
    return wavPath;
}
