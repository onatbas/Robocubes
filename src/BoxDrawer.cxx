//
// Created by Onat Bas on 03/01/17.
//

#include <Box.hxx>
#include "BoxDrawer.hxx"
#include <iostream>
#include "PNGLoader.hxx"
#include "PNGDrawer.hxx"

bool BoxDrawer::draw(Renderable *renderable, const Box &box) {
    return drawAt(renderable, box, DrawPosition(0, 0), Scale(1));
}


BoxDrawer::BoxDrawer(PNG png) : png(png){
}

bool BoxDrawer::drawAt(Renderable *renderable, const Box &box, const DrawPosition &position, Scale scale) {
    PNGDrawer drawer(renderable);
    drawer.draw(png, position, scale);

    return true;
}
