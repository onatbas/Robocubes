//
// Created by Onat Bas on 05/01/17.
//

#include "MouseClickTracker.hxx"
#include "DrawPosition.hxx"
#include "BoxPositionCalculator.hxx"
#include "MovementChecker.hxx"
#include "BoxExistanceChecker.hxx"

using namespace entityx;

MouseClickTracker::MouseClickTracker(GameLooper *looper, EntityFactory *factory, Dimension windowDimensions) : looper(
        *looper) {
    looper->observe(SDL_MOUSEBUTTONDOWN, 0, [=](const char *data) {
        const SDL_Event *e = (SDL_Event *) data;
        const SDL_MouseButtonEvent &button = e->button;
        const DrawPosition &clickPosition = DrawPosition(button.x, button.y);

        BoxPositionCalculator calculator;
        BoxPosition boxPosition = calculator.clickToBox(clickPosition, windowDimensions);
        this->clickPosition = boxPosition;
    });
}

void MouseClickTracker::update(EntityManager &entities, EventManager &events, TimeDelta dt) {
    BoxPosition click;
    if (clickPosition.getClick(click)) {
        MovementChecker checker;
        BoxExistanceChecker existanceChecker(&entities);
        if (!checker.isSomethingMoving(entities)) {
            if (existanceChecker.check(click))
            looper.sendSignal(BOXESEVENT_BOX_CLICKED, 0, (char *) &click);
        }
    }
}
