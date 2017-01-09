//
// Created by Onat Bas on 06/01/17.
//

#ifndef BOXESGAME_BOXRENDERERSUBSYSTEM_HXX
#define BOXESGAME_BOXRENDERERSUBSYSTEM_HXX

#include "EntityFactory.hxx"
#include "GameSystem.hxx"
#include "BackgroundRendererSubSystem.hxx"
#include "RenderingSubSystem.hxx"

class BoxRendererSubSystem : public RenderingSubSystem{

protected:
public:
    virtual void
    render(entityx::EntityManager &entities, Renderable &renderable, Window *window, entityx::TimeDelta delta) override;
};

#endif //BOXESGAME_BOXRENDERERSUBSYSTEM_HXX
