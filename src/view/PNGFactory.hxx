//
// Created by Onat Bas on 06/01/17.
//

#ifndef BOXESGAME_PNGFACTORY_HXX
#define BOXESGAME_PNGFACTORY_HXX

#include <PNG.hxx>
#include "EntityFactory.hxx"
#include "systems/GameSystem.hxx"
#include "systems/BackgroundRendererSubSystem.hxx"
#include <string>

class PNGFactory {

public:
    PNGFactory(Window *window);
    PNG *getPNG(std::string path);

private:
    Window *window;
};

#endif //BOXESGAME_PNGFACTORY_HXX
