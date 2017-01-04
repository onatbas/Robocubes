//
// Created by Onat Bas on 03/01/17.
//

#ifndef BOXESGAME_BACKGROUNDRENDERER_HXX
#define BOXESGAME_BACKGROUNDRENDERER_HXX

#include <string>
#include <Window.hxx>
#include <memory>
#include <PNG.hxx>
#include <GameLooper.hxx>
#include "WindowDimensionGetter.hxx"
#include "../tests/EntityFactory.hxx"

class BackgroundRendererEntityFactory {
public:

    BackgroundRendererEntityFactory(const std::string &pathToPng, EntityFactory *factory);

protected:
    std::string pathToPng;

};

#endif //BOXESGAME_BACKGROUNDRENDERER_HXX
