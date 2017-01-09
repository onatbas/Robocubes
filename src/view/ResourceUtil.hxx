//
// Created by Onat Bas on 05/01/17.
//

#ifndef BOXESGAME_RESOURCEUTIL_HXX
#define BOXESGAME_RESOURCEUTIL_HXX

#include <string>
#include "logic/Box.hxx"

class ResourceUtil {
public:
    std::string getMaterialsPath() const;
    std::string getBoxPath(const Box &box, bool alternative) const;
    std::string getBackgroundPath() const;
    std::string getTerrainPath() const;

    std::string getRandomSmoke() const;

    std::string getLogoPath();
    const std::string getStartPath();
    std::string getMusicPath();

    int getSmokeSize() const;
    std::string getSmokeNew(int i) const;

    std::string getSoundLevelBegin();
    std::string getClickedSound();
    std::string getBoardPath();
    std::string getTTFPath();
    std::string getGameOverPath();
    std::string getGetReadyPath();
};

#endif //BOXESGAME_RESOURCEUTIL_HXX
