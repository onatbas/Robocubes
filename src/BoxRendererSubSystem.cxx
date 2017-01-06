//
// Created by Onat Bas on 06/01/17.
//

#include "RenderingSystem.hxx"
#include <PNGDrawer.hxx>
#include <Window.hxx>
#include "BoxRendererSubSystem.hxx"
#include "Box.hxx"
#include "ResourceUtil.hxx"
#include "BoxDrawer.hxx"
#include "BoxPositionCalculator.hxx"
#include "WindowDimensionGetter.hxx"

void BoxRendererSubSystem::render(entityx::EntityManager &entities, Renderable &renderable, Window *window) {
    entities.each<Box, BoxPosition, Scale>([&](entityx::Entity entity, Box &box, BoxPosition &position, Scale &s) {
        BoxPositionCalculator boxPositionCalculator;
        PNGFactory factory(window);
        ResourceUtil resourceUtil;
        WindowDimensionGetter getter;


        PNG *png = factory.getPNG(resourceUtil.getBoxPath(box));
        BoxDrawer drawer(*png);
        auto windowDimensions = getter.getDimensionsOfWindows(window);

        DrawPosition drawPosition = boxPositionCalculator.boxToDrawing(position, windowDimensions, s);
        drawer.drawAt(&renderable, box, drawPosition, s);
    });
}
