//
// Created by Onat Bas on 07/01/17.
//

#ifndef BOXESGAME_MOVEMENTCHECKER_HXX
#define BOXESGAME_MOVEMENTCHECKER_HXX

#include <entityx/entityx.h>

class MovementChecker {

public:
    bool isSomethingMoving(entityx::EntityManager &entities) const;
};

#endif //BOXESGAME_MOVEMENTCHECKER_HXX
