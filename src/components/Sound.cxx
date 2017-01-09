//
// Created by Onat Bas on 08/01/17.
//

#include "Sound.hxx"

Sound::Sound(const std::string &wavPath) : wavPath(wavPath) {
}

const std::string &Sound::getWavPath() const {
    return wavPath;
}

bool Sound::isLoaded() const {
    return loaded;
}

void Sound::setChunk(Mix_Chunk *chunk) {
    Sound::chunk = chunk;
    loaded = true;
}

Mix_Chunk *Sound::getChunk() const {
    return chunk;
}
