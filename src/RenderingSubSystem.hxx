//
// Created by Onat Bas on 06/01/17.
//

#ifndef BOXESGAME_RENDERINGSUBSYSTEM_HXX
#define BOXESGAME_RENDERINGSUBSYSTEM_HXX

#include "Window.hxx"
#include <entityx/entityx.h>
#include "Renderable.hxx"
#include "Dimension.hxx"

class RenderingSubSystem {
public:
    virtual void
    render(entityx::EntityManager &entities, Renderable &renderable, Window *window, entityx::TimeDelta delta) = 0;
};

#endif //BOXESGAME_RENDERINGSUBSYSTEM_HXX
