//
// Created by Onat Bas on 04/01/17.
//

#ifndef BOXESGAME_RENDERINGSYSTEM_HXX
#define BOXESGAME_RENDERINGSYSTEM_HXX

#include <PNG.hxx>
#include <map>
#include <components/BackgroundComponent.hxx>
#include "EntityFactory.hxx"
#include "GameSystem.hxx"
#include "Window.hxx"
#include "components/BoxPosition.hxx"
#include "components/Scale.hxx"
#include "PNGFactory.hxx"
#include "TerrainRendererSubSystem.hxx"
#include "BoxRendererSubSystem.hxx"

class RenderingSystem : public GameSystem<RenderingSystem>, public BoxRendererSubSystem {

public:
    RenderingSystem(EntityFactory *factory, Window *window);
    virtual void
    update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) override;

    void addSubSystem(std::shared_ptr<RenderingSubSystem> sub);

private:
    Window *window;
    EntityFactory *factory;
    void renderSubsystems(entityx::EntityManager &entities, Renderable &renderable, entityx::TimeDelta dt) const;
    std::vector<std::shared_ptr<RenderingSubSystem> > subsystems;
};

#endif //BOXESGAME_RENDERINGSYSTEM_HXX
