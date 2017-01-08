//
// Created by Onat Bas on 05/01/17.
//

#ifndef BOXESGAME_RESOURCEUTIL_HXX
#define BOXESGAME_RESOURCEUTIL_HXX

#include <string>
#include "Box.hxx"

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

    std::string getSoundLevelBegin();
};

#endif //BOXESGAME_RESOURCEUTIL_HXX
