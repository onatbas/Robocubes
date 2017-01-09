//
// Created by Onat Bas on 08/01/17.
//

#ifndef BOXESGAME_BOXEXISTANCECHECKER_HXX
#define BOXESGAME_BOXEXISTANCECHECKER_HXX

#include "components/BoxPosition.hxx"
#include <entityx/entityx.h>

class BoxExistanceChecker {

public:
    BoxExistanceChecker(entityx::EntityManager *manager);
    bool check(BoxPosition position) const;

private:
    entityx::EntityManager *manager;
};

#endif //BOXESGAME_BOXEXISTANCECHECKER_HXX
