//
// Created by Onat Bas on 06/01/17.
//

#include "RenderingSystem.hxx"
#include <PNGDrawer.hxx>
#include <DimensionCalculator.hxx>
#include "TerrainRenderer.hxx"
#include "TerrainComponent.hxx"
#include "WindowDimensionGetter.hxx"

void TerrainRendererSubSystem::render(entityx::EntityManager &entities, Renderable &renderable, Window *window) {
    entities.each<TerrainComponent, Scale>([&](entityx::Entity entity, TerrainComponent &background, Scale &s) {
        PNGFactory factory(window);
        WindowDimensionGetter getter;
        const Dimension &windowDimensions = getter.getDimensionsOfWindows(window);
        PNG *png = factory.getPNG(background.getPath());
        DrawPosition origin(-2, windowDimensions.getHeight() - 90);

        PNGDrawer drawer(&renderable);
        drawer.draw(*png, origin, s);
    });
}