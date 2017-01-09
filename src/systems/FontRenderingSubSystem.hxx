//
// Created by Onat Bas on 08/01/17.
//

#ifndef BOXESGAME_FONTRENDERINGSUBSYSTEM_HXX
#define BOXESGAME_FONTRENDERINGSUBSYSTEM_HXX

#include <SDL_ttf.h>
#include "RenderingSubSystem.hxx"

class FontRenderingSubSystem : public RenderingSubSystem {
public:
    FontRenderingSubSystem();
    virtual void
    render(entityx::EntityManager &entities, Renderable &renderable, Window *window, entityx::TimeDelta delta) override;
    virtual ~FontRenderingSubSystem();
    bool success;

    TTF_Font *gFont;
};

#endif //BOXESGAME_FONTRENDERINGSUBSYSTEM_HXX
