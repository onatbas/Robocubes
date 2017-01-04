//
// Created by Onat Bas on 03/01/17.
//

#include <PNGLoader.hxx>
#include "BackgroundRendererEntityFactory.hxx"
#include "../tests/EntityFactory.hxx"
#include "BackgroundComponent.hxx"
#include <PNGDrawer.hxx>
#include <WindowUpdater.hxx>
#include <DimensionCalculator.hxx>
/*
void BackgroundRendererEntityFactory::render() {
    DimensionCalculator calculator;
    PNGDrawer drawer(window.get());
    WindowDimensionGetter getter;

    Dimension pngDimensions = calculator.calculate(png);
    Dimension dimensions = getter.getDimensionsOfWindows(window.get());

    Dimension difference = pngDimensions - dimensions;
    DrawPosition origin(-difference.getWidth(), -difference.getHeight());
    drawer.draw(png, origin);
}*/

BackgroundRendererEntityFactory::BackgroundRendererEntityFactory(const std::string &pathToPng, EntityFactory *factory) {
    auto e = factory->entities.create();
    e.assign<BackgroundComponent>(pathToPng);

    /*this->window = window;
    PNGLoader loader;
    this->png = loader.load(pathToPng, window.get());

    looper.observe(BOXESEVENT_ENTER_FRAME, 0, [&](SDL_Event e) {
        render();
    });
    render();*/
}


