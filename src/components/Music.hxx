//
// Created by Onat Bas on 08/01/17.
//

#ifndef BOXESGAME_MUSIC_HXX
#define BOXESGAME_MUSIC_HXX

#include <string>

class Music {

private:

    std::string wavPath;
public:
    Music(const std::string &wavPath);
    std::string getWavPath() const;
};

#endif //BOXESGAME_MUSIC_HXX
