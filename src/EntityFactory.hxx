//
// Created by Onat Bas on 04/01/17.
//

#ifndef BOXESGAME_ENTITYFACTORY_HXX
#define BOXESGAME_ENTITYFACTORY_HXX

#include <entityx/entityx.h>
#include "GameLooper.hxx"
#include <vector>

class EntityFactory : public entityx::EntityX {

private:
    GameLooper *looper;
    bool active;
public:
    EntityFactory(GameLooper *looper);

    template<typename T>
    void addSystem(std::shared_ptr<T> system) {
        systems.add(system);
        systemUpdates.push_back([&](entityx::TimeDelta delta) {
            systems.update<T>(delta);
        });
        systems.configure();
    }

    void update(entityx::TimeDelta dt);
    void setActive(bool active);

private:
    std::vector<std::function<void(entityx::TimeDelta)> > systemUpdates;
};

#endif //BOXESGAME_ENTITYFACTORY_HXX
