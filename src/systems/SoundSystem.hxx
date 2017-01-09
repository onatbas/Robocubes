//
// Created by Onat Bas on 08/01/17.
//

#ifndef BOXESGAME_SOUNDSYSTEM_HXX
#define BOXESGAME_SOUNDSYSTEM_HXX

#include "GameSystem.hxx"

class SoundSystem : public GameSystem<SoundSystem> {
public:
    SoundSystem();
    virtual void
    update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) override;
    bool success;
};

#endif //BOXESGAME_SOUNDSYSTEM_HXX
