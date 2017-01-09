//
// Created by Onat Bas on 08/01/17.
//

#include "VelocitySystem.hxx"
#include "components/Velocity.hxx"
#include "components/DrawPosition.hxx"
#include "view/BoxDrawingConfiguration.hxx"

using namespace entityx;
void VelocitySystem::update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) {
entities.each<Velocity, DrawPosition>([&](Entity entity, Velocity &v, DrawPosition &d){

    if (v.shouldWait(dt))
        return;

    int x = v.getSpeedX() + d.getX();
    int y = v.getSpeedY() + d.getY();

    if (ifLooping)
    {
        BoxDrawingConfiguration config;
        Dimension dimension = config.getBoxDimensions();
        if( x > windowDimensions.getWidth())
            x = -dimension.getWidth();
        if (y > windowDimensions.getHeight())
            y = -dimension.getHeight();
    }
    d = DrawPosition(x, y);

});
}

VelocitySystem::VelocitySystem(bool ifLooping, const Dimension &windowDimensions) : ifLooping(ifLooping),
                                                                                    windowDimensions(windowDimensions) {
}
