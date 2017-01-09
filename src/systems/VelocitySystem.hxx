//
// Created by Onat Bas on 08/01/17.
//

#ifndef BOXESGAME_VELOCITYSYSTEM_HXX
#define BOXESGAME_VELOCITYSYSTEM_HXX

#include "systems/GameSystem.hxx"
#include "components/Dimension.hxx"
class VelocitySystem : public GameSystem<VelocitySystem>{
public:
    VelocitySystem(bool ifLooping, const Dimension &windowDimensions);
    virtual void
    update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) override;

private:

    bool ifLooping;
    Dimension windowDimensions;
};

#endif //BOXESGAME_VELOCITYSYSTEM_HXX
