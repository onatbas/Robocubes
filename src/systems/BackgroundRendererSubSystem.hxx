//
// Created by Onat Bas on 06/01/17.
//

#ifndef BOXESGAME_BACKGROUNDRENDERER_HXX
#define BOXESGAME_BACKGROUNDRENDERER_HXX

#include "EntityFactory.hxx"
#include "systems/GameSystem.hxx"
#include "systems/RenderingSubSystem.hxx"

class BackgroundRendererSubSystem : public RenderingSubSystem {

public:
    virtual void
    render(entityx::EntityManager &entities, Renderable &renderable, Window *window, entityx::TimeDelta delta) override;
};

#endif //BOXESGAME_BACKGROUNDRENDERER_HXX
