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
    std::string getBoxPath(const Box &box) const;
    std::string getBackgroundPath() const;
    std::string getTerrainPath() const;

    std::string getRandomSmoke() const;


};

#endif //BOXESGAME_RESOURCEUTIL_HXX
