//
// Created by Onat Bas on 03/01/17.
//

#include <PNGLoader.hxx>
#include "BackgroundRenderer.hxx"
#include <PNGDrawer.hxx>
#include <WindowUpdater.hxx>
#include <DimensionCalculator.hxx>

void BackgroundRenderer::render() {
    DimensionCalculator calculator;
    PNGDrawer drawer(window.get());
    WindowDimensionGetter getter;

    Dimension pngDimensions = calculator.calculate(png);
    Dimension dimensions = getter.getDimensionsOfWindows(window.get());

    Dimension difference = pngDimensions - dimensions;
    DrawPosition origin(-difference.getWidth(), -difference.getHeight());
    drawer.draw(png, origin);
}

BackgroundRenderer::BackgroundRenderer(const std::string &pathToPng, const std::shared_ptr<Window> &window,
                                       GameLooper &looper) {
    this->window = window;
    PNGLoader loader;
    this->png = loader.load(pathToPng, window.get());

    looper.observe(BOXESEVENT_ENTER_FRAME, 0, [&](SDL_Event e) {
        render();
    });
    render();
}


