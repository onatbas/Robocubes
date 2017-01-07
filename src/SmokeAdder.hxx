//
// Created by Onat Bas on 06/01/17.
//

#ifndef BOXESGAME_SMOKEADDER_HXX
#define BOXESGAME_SMOKEADDER_HXX

#include "DrawPosition.hxx"
#include "entityx/entityx.h"

class SmokeAdder {
public:
    void add(entityx::EntityManager &entities, const DrawPosition &drawPosition) const;
};

#endif //BOXESGAME_SMOKEADDER_HXX
