//
// Created by Onat Bas on 08/01/17.
//

#include "BoxExistanceChecker.hxx"

using namespace entityx;

BoxExistanceChecker::BoxExistanceChecker(entityx::EntityManager *manager) : manager(manager) {
}

bool BoxExistanceChecker::check(BoxPosition checkAgainst) const {
    bool found = false;
    manager->each<BoxPosition>([&](Entity entity, BoxPosition &position){
        if (position == checkAgainst)
            found = true;
    });
    return found;
}
