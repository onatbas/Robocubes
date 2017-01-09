//
// Created by Onat Bas on 08/01/17.
//

#ifndef BOXESGAME_SOUND_HXX
#define BOXESGAME_SOUND_HXX
#include <string>
#include <SDL_mixer.h>

class Sound {
public:
    Sound(const std::string &wavPath);
    const std::string &getWavPath() const;

private:
    std::string wavPath;

    bool loaded;
    Mix_Chunk *chunk;
public:
    bool isLoaded() const;
    Mix_Chunk *getChunk() const;
    void setChunk(Mix_Chunk *chunk);
};

#endif //BOXESGAME_SOUND_HXX
