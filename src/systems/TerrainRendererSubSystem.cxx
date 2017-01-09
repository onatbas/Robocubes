//
// Created by Onat Bas on 06/01/17.
//

#include "RenderingSystem.hxx"
#include <view/PNGDrawer.hxx>
#include <view/PNGDimensionGetter.hxx>
#include "view/TerrainRenderer.hxx"
#include "components/TerrainComponent.hxx"
#include "view/WindowDimensionGetter.hxx"

void TerrainRendererSubSystem::render(entityx::EntityManager &entities, Renderable &renderable, Window *window, entityx::TimeDelta delta) {
    entities.each<TerrainComponent, Scale>([&](entityx::Entity entity, TerrainComponent &background, Scale &s) {
        PNGFactory factory(window);
        WindowDimensionGetter getter;
        const Dimension &windowDimensions = getter.getDimensionsOfWindows(window);
        PNG *png = factory.getPNG(background.getPath());
        DrawPosition origin(-20, windowDimensions.getHeight() - 90);

        PNGDrawer drawer(&renderable);
        drawer.draw(*png, origin, s);
    });
}