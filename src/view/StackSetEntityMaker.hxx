//
// Created by Onat Bas on 04/01/17.
//

#ifndef BOXESGAME_STACKRENDERER_HXX
#define BOXESGAME_STACKRENDERER_HXX
#include "logic/StackSet.hxx"
#include "Window.hxx"
#include "logic/Box.hxx"
#include "BoxDrawer.hxx"
#include "decorators/GameLooper.hxx"
#include "EntityFactory.hxx"
#include "BoxDrawingConfiguration.hxx"

class StackSetEntityMaker : public BoxDrawingConfiguration {

public:
    StackSetEntityMaker(EntityFactory *factory);
    void makeEntities(const StackSet &set);

private:
    EntityFactory *factory;
};

#endif //BOXESGAME_STACKRENDERER_HXX
