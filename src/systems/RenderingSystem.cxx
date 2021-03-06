//
// Created by Onat Bas on 04/01/17.
//

#include <view/Window.hxx>
#include <view/PNGDrawer.hxx>
#include <view/PNGLoader.hxx>
#include <view/BoxDrawer.hxx>
#include "RenderingSystem.hxx"

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
    renderSubsystems(entities, renderable, dt);
    updater.updateWindow(window);
}

void RenderingSystem::renderSubsystems(entityx::EntityManager &entities, Renderable &renderable,
                                       entityx::TimeDelta dt) const {

    for (auto sub : subsystems)
        sub->render(entities, renderable, window, dt);
}

void RenderingSystem::addSubSystem(std::shared_ptr<RenderingSubSystem> sub) {
    subsystems.push_back(sub);
}

