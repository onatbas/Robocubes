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
#include <Scale.hxx>
#include "RenderingSystem.hxx"
#include "EntityFactory.hxx"

std::string operator<<(std::string ss, const char *c)
{
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


RenderingSystem::RenderingSystem(EntityFactory *factory, Window *window)
        : factory(factory), window(window){

}

void RenderingSystem::update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) {

    WindowRefGetter getter(window);
    Renderable renderable(SDL_GetWindowSurface(getter.getWindowRef()));

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

    entities.each<Box, BoxPosition, Scale>([&](entityx::Entity entity, Box &box, BoxPosition &position, Scale &s){
        PNG *png = getPNG(getBoxPath(box));
        BoxDrawer drawer(*png);
        WindowDimensionGetter getter;
        Dimension dimensions = getter.getDimensionsOfWindows(window);

        DrawPosition drawPosition(position.getX() * 70, dimensions.getHeight() - (position.getY()+1)*70);
        drawer.drawAt(&renderable, box, drawPosition);
    });

    WindowUpdater updater;
    updater.updateWindow(window);
}

PNG *RenderingSystem::getPNG(const BackgroundComponent &background) {

    if (pngs[background.getPath()] == nullptr){
        PNGLoader loader;
        pngs[background.getPath()] = std::make_shared<PNG>(loader.load(background.getPath(), window));
    }
    return pngs[background.getPath()].get();
}