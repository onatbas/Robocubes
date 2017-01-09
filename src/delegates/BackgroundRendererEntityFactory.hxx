//
// Created by Onat Bas on 03/01/17.
//

#ifndef BOXESGAME_BACKGROUNDRENDERERENTITYFACTORY_HXX
#define BOXESGAME_BACKGROUNDRENDERERENTITYFACTORY_HXX

#include <string>
#include <view/Window.hxx>
#include <memory>
#include <view/PNG.hxx>
#include <decorators/GameLooper.hxx>
#include "view/WindowDimensionGetter.hxx"
#include "EntityFactory.hxx"

class BackgroundRendererEntityFactory {
public:

    BackgroundRendererEntityFactory(const std::string &pathToPng, EntityFactory *factory);

protected:
    std::string pathToPng;

};

#endif //BOXESGAME_BACKGROUNDRENDERERENTITYFACTORY_HXX
