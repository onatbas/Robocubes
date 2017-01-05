//
// Created by Onat Bas on 05/01/17.
//

#ifndef BOXESGAME_TERRAINCOMPONENT_HXX
#define BOXESGAME_TERRAINCOMPONENT_HXX

#include <string>
class TerrainComponent {
public:
    TerrainComponent(const std::string &path);
    const std::string &getPath() const;
private:
    std::string path;
};

#endif //BOXESGAME_TERRAINCOMPONENT_HXX
