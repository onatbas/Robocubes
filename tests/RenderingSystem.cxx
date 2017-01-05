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

std::string operator<<(std::string ss, const char *c) {
    ss.append(std::string(c));
    return ss;
}

std::string getMaterialsPath() {
    return "boxesGame_tests_materials/";
}

std::string getBoxPath(const Box &box) {
    switch (box.getColor()) {
        case GREEN:
            return getMaterialsPath() << "block_green.png"; //<< "alienGreen_square.png";
        case BLUE:
            return getMaterialsPath() << "block_weird.png"; //<< "alienBlue_square.png";
        case RED:
            return getMaterialsPath() << "block_red.png"; //"alienPink_square.png";
    }
    return "";
}

RenderingSystem::RenderingSystem(EntityFactory *factory, Window *window) : factory(factory),
                                                                           window(window) {

}

void RenderingSystem::update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) {

    WindowRefGetter getter(window);
    SDL_Surface *const pSurface = SDL_GetWindowSurface(getter.getWindowRef());
    Renderable renderable(pSurface);
    SDL_FillRect( pSurface, NULL, SDL_MapRGB( pSurface->format, 0xD0, 0xF4, 0xF7 ) );


    entities.each<BackgroundComponent, Scale>([&](entityx::Entity entity, BackgroundComponent &background, Scale &s) {
        DimensionCalculator calculator;
        PNGDrawer drawer(&renderable);
        WindowDimensionGetter getter;
        PNG *png = getPNG(background);

        Dimension pngDimensions = calculator.calculate(*png);
        pngDimensions = Dimension(pngDimensions.getWidth() * s.scale, pngDimensions.getHeight() * s.scale);
        Dimension dimensions = getter.getDimensionsOfWindows(window);

        Dimension difference = pngDimensions - dimensions;
        DrawPosition origin(-difference.getWidth(), -difference.getHeight());
        drawer.draw(*png, origin, s);
    });

    entities.each<Box, BoxPosition, Scale>([&](entityx::Entity entity, Box &box, BoxPosition &position, Scale &s) {
        PNG *png = getPNG(getBoxPath(box));
        BoxDrawer drawer(*png);
        WindowDimensionGetter getter;
        DimensionCalculator calculator;
        const Dimension &pngDimension = calculator.calculate(*png);
        const Dimension &addedDimension = Dimension(pngDimension.getWidth() - 1, pngDimension.getHeight() - 1);
        Dimension dimensions = getter.getDimensionsOfWindows(window);

        DrawPosition drawPosition(position.getX() * addedDimension.getWidth() * s.scale,
                                  dimensions.getHeight() - (position.getY() + 1) * (addedDimension.getHeight()) * s.scale - 20);
        drawer.drawAt(&renderable, box, drawPosition, s);
    });

    WindowUpdater updater;
    updater.updateWindow(window);
}

PNG *RenderingSystem::getPNG(const BackgroundComponent &background) {

    if (pngs[background.getPath()] == nullptr) {
        PNGLoader loader;
        pngs[background.getPath()] = std::make_shared<PNG>(loader.load(background.getPath(), window));
    }
    return pngs[background.getPath()].get();
}