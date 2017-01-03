//
// Created by Onat Bas on 03/01/17.
//

#ifndef BOXESGAME_BOXRENDERER_HXX
#define BOXESGAME_BOXRENDERER_HXX

#include "Window.hxx"
#include "Box.hxx"
#include "IMGInitializer.hxx"
#include "WindowUpdater.hxx"
#include "PNG.hxx"
#include <string>
#include "DrawPosition.hxx"

class BoxDrawer {
public:
    BoxDrawer(std::string path);
    bool draw(Window *window, const Box &box);
    bool drawAt(Window *window, const Box &box, const DrawPosition& position);

private:
    std::string texturePath;
    void loadPNG(const Window *window);
    PNG png;
};

#endif //BOXESGAME_BOXRENDERER_HXX
