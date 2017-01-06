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
#include "../tests/Offset.hxx"

DrawPosition operator-(const DrawPosition &position, const Offset &offset)
{
    return DrawPosition(position.getX() - offset.getX(), position.getY() - offset.getY());
}

void BoxRendererSubSystem::render(entityx::EntityManager &entities, Renderable &renderable, Window *window, entityx::TimeDelta delta) {
    entities.each<Box, BoxPosition, Scale, Offset>([&](entityx::Entity entity, Box &box, BoxPosition &position, Scale &s, Offset &offset) {
        BoxPositionCalculator boxPositionCalculator;
        PNGFactory factory(window);
        ResourceUtil resourceUtil;
        WindowDimensionGetter getter;


        PNG *png = factory.getPNG(resourceUtil.getBoxPath(box));
        BoxDrawer drawer(*png);
        auto windowDimensions = getter.getDimensionsOfWindows(window);

        DrawPosition drawPosition = boxPositionCalculator.boxToDrawing(position, windowDimensions, s) - offset;
        drawer.drawAt(&renderable, box, drawPosition, s);
    });
}
