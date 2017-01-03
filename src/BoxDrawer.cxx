//
// Created by Onat Bas on 03/01/17.
//

#include <Box.hxx>
#include "BoxDrawer.hxx"
#include <iostream>
#include "PNGLoader.hxx"
#include "PNGDrawer.hxx"

bool BoxDrawer::draw(Window *window, const Box &box) {
    return drawAt(window, box, DrawPosition(0, 0));
}

void BoxDrawer::loadPNG(const Window *window) {
    PNGLoader loader;
    if (!png.isInitialized()) {

        IMGInitializer initializer;
        if (!initializer.initializeIMG())
            return;

        png = loader.load(texturePath, window);
    }
}

BoxDrawer::BoxDrawer(std::string path) {
    this->texturePath = path;
}

bool BoxDrawer::drawAt(Window *window, const Box &box, const DrawPosition &position) {
    loadPNG(window);

    PNGDrawer drawer(window);
    drawer.draw(png, position);

    WindowUpdater updater;
    updater.updateWindow(window);

    return true;
}
