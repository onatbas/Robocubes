//
// Created by Onat Bas on 06/01/17.
//

#include "RenderingSystem.hxx"
#include <PNGDimensionGetter.hxx>
#include "BackgroundRendererSubSystem.hxx"
#include "WindowDimensionGetter.hxx"
#include "PNGDrawer.hxx"

void BackgroundRendererSubSystem::render(entityx::EntityManager &entities, Renderable &renderable, Window *window, entityx::TimeDelta delta) {
    entities.each<BackgroundComponent, Scale>([&](entityx::Entity entity, BackgroundComponent &background, Scale &s) {
        PNGFactory factory(window);
        WindowDimensionGetter getter;
        PNGDimensionGetter calculator;

        PNG *png = factory.getPNG(background.getPath());
        const Dimension &windowDimension = getter.getDimensionsOfWindows(window);
        const Dimension &pngDimensions = calculator.calculate(*png);
        const Dimension & scaled = Dimension(pngDimensions.getWidth() * s.scale, pngDimensions.getHeight() * s.scale);
        const Dimension & difference = scaled - windowDimension;
        DrawPosition origin(-difference.getWidth(), -difference.getHeight());

        PNGDrawer drawer(&renderable);
        drawer.draw(*png, origin, s);
    });
}