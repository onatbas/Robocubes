//
// Created by Onat Bas on 03/01/17.
//

#include <logic/Box.hxx>
#include "BoxDrawer.hxx"
#include "PNGDrawer.hxx"
#include "BoxDrawingConfiguration.hxx"
#include "PNGDimensionGetter.hxx"

bool BoxDrawer::draw(Renderable *renderable, const Box &box) {
    return drawAt(renderable, box, DrawPosition(0, 0), Scale(1));
}

BoxDrawer::BoxDrawer(PNG png) : png(png) {
}

bool BoxDrawer::drawAt(Renderable *renderable, const Box &box, const DrawPosition &position, Scale scale) {
    PNGDrawer drawer(renderable);

    BoxDrawingConfiguration config;
    Dimension boxDimension = config.getBoxDimensions();
    
    PNGDimensionGetter getter;
    Dimension pngDimension = getter.calculate(png);

    DrawPosition withOffset = DrawPosition(position.getX(), position.getY() + (boxDimension.getHeight() - pngDimension.getHeight()) * scale.scale);

    drawer.draw(png, withOffset, scale);
    return true;
}
