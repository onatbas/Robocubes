//
// Created by Onat Bas on 06/01/17.
//

#ifndef BOXESGAME_TERRAINRENDERER1_HXX
#define BOXESGAME_TERRAINRENDERER1_HXX

#include "EntityFactory.hxx"
#include "GameSystem.hxx"
#include "Dimension.hxx"
#include "WindowCleaner.hxx"
#include "RenderingSubSystem.hxx"

class TerrainRendererSubSystem : public RenderingSubSystem {

public:
    virtual void render(entityx::EntityManager &entities, Renderable &renderable, Window *window) override;
};

#endif //BOXESGAME_TERRAINRENDERER1_HXX
