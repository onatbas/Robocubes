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

RenderingSystem::RenderingSystem(EntityFactory *factory, Window *window) : factory(factory),
                                                                           window(window) {

}

void RenderingSystem::update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) {

    WindowRefGetter getter(window);
    WindowDimensionGetter dimGetter;
    Dimension dimensions = dimGetter.getDimensionsOfWindows(window);
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

        Dimension difference = pngDimensions - dimensions;
        DrawPosition origin(-difference.getWidth(), -difference.getHeight());
        drawer.draw(*png, origin, s);
    });


    entities.each<TerrainComponent, Scale>([&](entityx::Entity entity, TerrainComponent &background, Scale &s) {
        PNG *png = getPNG(background.getPath());
        DrawPosition origin(-2, dimensions.getHeight() - 90);
        drawer.draw(*png, origin, s);
    });



    entities.each<Box, BoxPosition, Scale>([&](entityx::Entity entity, Box &box, BoxPosition &position, Scale &s) {
        PNG *png = getPNG(resourceUtil.getBoxPath(box));
        BoxDrawer drawer(*png);
        const Dimension &pngDimension = Dimension(170, 150);
        const Dimension &addedDimension = Dimension(pngDimension.getWidth() - 1, pngDimension.getHeight() - 1);

        DrawPosition drawPosition(position.getX() * addedDimension.getWidth() * s.scale,
                                  dimensions.getHeight() - (position.getY() + 1) * (addedDimension.getHeight()) * s.scale - 90);
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