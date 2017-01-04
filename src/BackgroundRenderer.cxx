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
    WindowUpdater updater;

    Dimension pngDimensions = calculator.calculate(png);
    Dimension dimensions = getDimensionsOfWindows();

    Dimension difference = pngDimensions - dimensions;
    DrawPosition origin(-difference.getWidth(), -difference.getHeight());

    drawer.draw(png, origin);
    updater.updateWindow(window.get());
}

Dimension BackgroundRenderer::getDimensionsOfWindows() const {
    WindowRefGetter getter(window.get());
    SDL_Surface *const pSurface = SDL_GetWindowSurface(getter.getWindowRef());
    return Dimension(pSurface->w, pSurface->h);
}

BackgroundRenderer::BackgroundRenderer(const std::string &pathToPng, const std::shared_ptr<Window> &window,
                                       GameLooper &looper) {
    this->window = window;
    PNGLoader loader;
    this->png = loader.load(pathToPng, window.get());

    looper.observe(SDL_WINDOWEVENT, SDL_WINDOWEVENT_SIZE_CHANGED, [&](SDL_Event e) {
        render();
    });
    render();
}


