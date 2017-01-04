//
// Created by Onat Bas on 03/01/17.
//

#ifndef BOXESGAME_BACKGROUNDRENDERER_HXX
#define BOXESGAME_BACKGROUNDRENDERER_HXX

#include <string>
#include <Window.hxx>
#include <memory>
#include <PNG.hxx>
#include <Dimension.hxx>
#include <GameLooper.hxx>

class BackgroundRenderer {
public:

    void render();
    BackgroundRenderer(const std::string &pathToPng, const std::shared_ptr<Window> &window, GameLooper &looper);

protected:
    std::shared_ptr<Window> window;
    PNG png;
    std::string pathToPng;

    Dimension getDimensionsOfWindows() const;
};

#endif //BOXESGAME_BACKGROUNDRENDERER_HXX
