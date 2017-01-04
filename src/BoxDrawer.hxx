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
#include "Renderable.hxx"

class BoxDrawer {
public:
    BoxDrawer(PNG png);
    bool draw(Renderable *renderable, const Box &box);
    bool drawAt(Renderable *renderable, const Box &box, const DrawPosition &position);

private:
    PNG png;
};

#endif //BOXESGAME_BOXRENDERER_HXX
