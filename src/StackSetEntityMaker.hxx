//
// Created by Onat Bas on 04/01/17.
//

#ifndef BOXESGAME_STACKRENDERER_HXX
#define BOXESGAME_STACKRENDERER_HXX
#include "StackSet.hxx"
#include "Window.hxx"
#include "Box.hxx"
#include "BoxDrawer.hxx"
#include "GameLooper.hxx"
#include "../tests/EntityFactory.hxx"

class StackSetEntityMaker {

public:
    StackSetEntityMaker(EntityFactory *factory);
    void makeEntities(const StackSet &stack);

private:
    EntityFactory *factory;
};

#endif //BOXESGAME_STACKRENDERER_HXX
