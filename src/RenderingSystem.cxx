//
// Created by Onat Bas on 04/01/17.
//

#include <Window.hxx>
#include <BackgroundComponent.hxx>
#include <DimensionCalculator.hxx>
#include <PNGDrawer.hxx>
#include <WindowDimensionGetter.hxx>
#include <PNGLoader.hxx>
#include <Box.hxx>
#include <BoxPosition.hxx>
#include <BoxDrawer.hxx>
#include "RenderingSystem.hxx"
#include "ResourceUtil.hxx"
#include "TerrainComponent.hxx"
#include "BoxPositionCalculator.hxx"

RenderingSystem::RenderingSystem(EntityFactory *factory, Window *window) : factory(factory),
                                                                           window(window) {

}

void RenderingSystem::update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) {

    WindowRefGetter getter(window);
    WindowDimensionGetter dimGetter;
    Dimension windowDimensions = dimGetter.getDimensionsOfWindows(window);
    DimensionCalculator calculator;

    SDL_Surface *const pSurface = SDL_GetWindowSurface(getter.getWindowRef());
    Renderable renderable(pSurface);
    PNGDrawer drawer(&renderable);
    ResourceUtil resourceUtil;

    SDL_FillRect( pSurface, NULL, SDL_MapRGB( pSurface->format, 0xD0, 0xF4, 0xF7 ) );


    entities.each<BackgroundComponent, Scale>([&](entityx::Entity entity, BackgroundComponent &background, Scale &s) {
        PNG *png = getPNG(background.getPath());

        Dimension pngDimensions = calculator.calculate(*png);
        pngDimensions = Dimension(pngDimensions.getWidth() * s.scale, pngDimensions.getHeight() * s.scale);

        Dimension difference = pngDimensions - windowDimensions;
        DrawPosition origin(-difference.getWidth(), -difference.getHeight());
        drawer.draw(*png, origin, s);
    });


    entities.each<TerrainComponent, Scale>([&](entityx::Entity entity, TerrainComponent &background, Scale &s) {
        PNG *png = getPNG(background.getPath());
        DrawPosition origin(-2, windowDimensions.getHeight() - 90);
        drawer.draw(*png, origin, s);
    });



    entities.each<Box, BoxPosition, Scale>([&](entityx::Entity entity, Box &box, BoxPosition &position, Scale &s) {
        PNG *png = getPNG(resourceUtil.getBoxPath(box));
        BoxDrawer drawer(*png);

        BoxPositionCalculator boxPositionCalculator;
        DrawPosition drawPosition = boxPositionCalculator.boxToDrawing(position, windowDimensions, s);
        drawer.drawAt(&renderable, box, drawPosition, s);
    });

    WindowUpdater updater;
    updater.updateWindow(window);
}

PNG *RenderingSystem::getPNG(std::string path) {

    if (pngs[path] == nullptr) {
        PNGLoader loader;
        pngs[path] = std::make_shared<PNG>(loader.load(path, window));
    }
    return pngs[path].get();
}