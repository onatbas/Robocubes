//
// Created by Onat Bas on 04/01/17.
//

#ifndef BOXESGAME_RENDERINGSYSTEM_HXX
#define BOXESGAME_RENDERINGSYSTEM_HXX

#include <PNG.hxx>
#include <map>
#include <BackgroundComponent.hxx>
#include "EntityFactory.hxx"
#include "GameSystem.hxx"
#include "Window.hxx"

class RenderingSystem : public GameSystem<RenderingSystem>{

public:
    RenderingSystem(EntityFactory *factory, Window *window);
private:
public:
    virtual void
    update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) override;
protected:
    EntityFactory *factory;
    Window *window;
    PNG *getPNG(const BackgroundComponent &background);
    std::map<std::string, std::shared_ptr<PNG> > pngs;
};

#endif //BOXESGAME_RENDERINGSYSTEM_HXX
