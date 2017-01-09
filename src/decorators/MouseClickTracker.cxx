//
// Created by Onat Bas on 05/01/17.
//

#include "MouseClickTracker.hxx"
#include "components/DrawPosition.hxx"
#include "view/BoxPositionCalculator.hxx"
#include "delegates/MovementChecker.hxx"
#include "delegates/BoxExistanceChecker.hxx"

using namespace entityx;

MouseClickTracker::MouseClickTracker(GameLooper *looper, EntityFactory *factory, Dimension windowDimensions) : looper(
        *looper), endGame(false) {
    looper->observe(SDL_MOUSEBUTTONDOWN, 0, [=](const char *data) {
        const SDL_Event *e = (SDL_Event *) data;
        const SDL_MouseButtonEvent &button = e->button;
        const DrawPosition &clickPosition = DrawPosition(button.x, button.y);

        BoxPositionCalculator calculator;
        BoxPosition boxPosition = calculator.clickToBox(clickPosition, windowDimensions);
        this->clickPosition = boxPosition;
    });

    looper->observe(BOXESGAME_ENDGAME, 0, [&](const char *data){
       this->endGame = true;
    });

    looper->observe(BOXESGAME_RESET_SUCCESS, 0, [&](const char *data){
        this->endGame = false;
    });
}

void MouseClickTracker::update(EntityManager &entities, EventManager &events, TimeDelta dt) {

    BoxPosition click;
    if (clickPosition.getClick(click)) {

        if (endGame) {
            looper.sendSignal(BOXESGAME_RESET_REQUEST, 0, nullptr);
            return;
        }


        MovementChecker checker;
        BoxExistanceChecker existanceChecker(&entities);
        if (!checker.isSomethingMoving(entities)) {
            if (existanceChecker.check(click))
            looper.sendSignal(BOXESEVENT_BOX_CLICKED, 0, (char *) &click);
        }
    }
}
