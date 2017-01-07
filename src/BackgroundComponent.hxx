//
// Created by Onat Bas on 04/01/17.
//

#ifndef BOXESGAME_PICTURECOMPONENT_HXX
#define BOXESGAME_PICTURECOMPONENT_HXX

#include <string>

class BackgroundComponent {

public:
    const std::string &getPath() const;
    BackgroundComponent(const std::string &path);

private:
    std::string path;
};

#endif //BOXESGAME_PICTURECOMPONENT_HXX
