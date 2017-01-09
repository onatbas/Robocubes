//
// Created by Onat Bas on 06/01/17.
//

#include "RenderingSystem.hxx"
#include <view/PNGDrawer.hxx>
#include <view/Window.hxx>
#include "BoxRendererSubSystem.hxx"
#include "logic/Box.hxx"
#include "view/ResourceUtil.hxx"
#include "view/BoxDrawer.hxx"
#include "view/BoxPositionCalculator.hxx"
#include "view/WindowDimensionGetter.hxx"
#include "components/Offset.hxx"
#include "view/GraphicsHolder.hxx"

DrawPosition operator-(const DrawPosition &position, const Offset &offset)
{
    return DrawPosition(position.getX() - offset.getX(), position.getY() - offset.getY());
}

void BoxRendererSubSystem::render(entityx::EntityManager &entities, Renderable &renderable, Window *window, entityx::TimeDelta delta) {
    entities.each<Box, BoxPosition, Scale, Offset, GraphicsHolder>([&](entityx::Entity entity, Box &box, BoxPosition &position, Scale &s, Offset &offset, GraphicsHolder &graphics) {
        BoxPositionCalculator boxPositionCalculator;
        PNGFactory factory(window);
        ResourceUtil resourceUtil;
        WindowDimensionGetter getter;

        PNG *png = factory.getPNG(resourceUtil.getBoxPath(box, graphics.getGraphics()));
        BoxDrawer drawer(*png);
        auto windowDimensions = getter.getDimensionsOfWindows(window);

        DrawPosition drawPosition = boxPositionCalculator.boxToDrawing(position, windowDimensions, s) - offset;
        drawer.drawAt(&renderable, box, drawPosition, s);
    });
}
