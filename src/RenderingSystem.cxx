//
// Created by Onat Bas on 04/01/17.
//

#include <Window.hxx>
#include <DimensionCalculator.hxx>
#include <PNGDrawer.hxx>
#include <WindowDimensionGetter.hxx>
#include <PNGLoader.hxx>
#include <BoxDrawer.hxx>
#include "RenderingSystem.hxx"
#include "ResourceUtil.hxx"

RenderingSystem::RenderingSystem(EntityFactory *factory, Window *window) : factory(factory),
                                                                           window(window) {

}

void RenderingSystem::update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) {

    WindowRefGetter dimGetter(window);
    Renderable renderable(SDL_GetWindowSurface(dimGetter.getWindowRef()));

    // Subsystems
    WindowCleaner cleaner;
    WindowUpdater updater;

    cleaner.clean(renderable, window);
    renderSubsystems(entities, renderable);
    updater.updateWindow(window);
}

void RenderingSystem::renderSubsystems(entityx::EntityManager &entities, Renderable &renderable) const {

    for (auto sub : subsystems)
        sub->render(entities, renderable, window);
}

void RenderingSystem::addSubSystem(std::shared_ptr<RenderingSubSystem> sub) {
    subsystems.push_back(sub);
}

