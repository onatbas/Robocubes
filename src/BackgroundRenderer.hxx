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

class BackgroundRenderer {
public:

    void render();
    BackgroundRenderer(const std::string &pathToPng, const std::shared_ptr<Window> &window, GameLooper &looper);

    std::shared_ptr<Window> window;
protected:
    PNG png;
    std::string pathToPng;

};

#endif //BOXESGAME_BACKGROUNDRENDERER_HXX
