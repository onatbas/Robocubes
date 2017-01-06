//
// Created by Onat Bas on 06/01/17.
//

#ifndef BOXESGAME_ANIMATIONSUBSYSTEM_HXX
#define BOXESGAME_ANIMATIONSUBSYSTEM_HXX

#include "RenderingSubSystem.hxx"

class AnimationSubSystem : public RenderingSubSystem {
public:
    virtual void
    render(entityx::EntityManager &entities, Renderable &renderable, Window *window, entityx::TimeDelta delta) override;
};

#endif //BOXESGAME_ANIMATIONSUBSYSTEM_HXX
