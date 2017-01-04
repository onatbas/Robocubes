//
// Created by Onat Bas on 04/01/17.
//

#include <Window.hxx>
#include <BackgroundComponent.hxx>
#include <DimensionCalculator.hxx>
#include <PNGDrawer.hxx>
#include <WindowDimensionGetter.hxx>
#include <PNGLoader.hxx>
#include "RenderingSystem.hxx"
#include "EntityFactory.hxx"

RenderingSystem::RenderingSystem(EntityFactory *factory, Window *window)
        : factory(factory), window(window){

}

void RenderingSystem::update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) {
    entities.each<BackgroundComponent>([&](entityx::Entity entity, BackgroundComponent &background) {
        DimensionCalculator calculator;
        PNGDrawer drawer(window);
        WindowDimensionGetter getter;
        PNG *png = getPNG(background);

        Dimension pngDimensions = calculator.calculate(*png);
        Dimension dimensions = getter.getDimensionsOfWindows(window);

        Dimension difference = pngDimensions - dimensions;
        DrawPosition origin(-difference.getWidth(), -difference.getHeight());
        drawer.draw(*png, origin);
    });
}

PNG *RenderingSystem::getPNG(const BackgroundComponent &background) {

    if (pngs[background.getPath()] == nullptr){
        PNGLoader loader;
        pngs[background.getPath()] = std::make_shared<PNG>(loader.load(background.getPath(), window));
    }
    return pngs[background.getPath()].get();
}