//
// Created by Onat Bas on 05/01/17.
//

#include "MouseClickTracker.hxx"
#include "DrawPosition.hxx"
#include "BoxPositionCalculator.hxx"
#include "MouseClicked.hxx"
#include "Box.hxx"
#include <iostream>

using namespace entityx;

MouseClickTracker::MouseClickTracker(GameLooper *looper, EntityFactory *factory, Dimension windowDimensions)
        : looper(*looper) {
    looper->observe(SDL_MOUSEBUTTONDOWN, 0, [=](SDL_Event e){
        const SDL_MouseButtonEvent &button = e.button;
        const DrawPosition &clickPosition = DrawPosition(button.x, button.y);

        BoxPositionCalculator calculator;
        BoxPosition boxPosition = calculator.clickToBox(clickPosition, windowDimensions);

        entityx::Entity resultEntity = factory->entities.create();
        resultEntity.assign<MouseClicked>(boxPosition);

        ComponentHandle<Box> box;
        ComponentHandle<BoxPosition> position;
        for (auto entity : factory->entities.entities_with_components<Box, BoxPosition>(box, position)) {
            if (*position.get() == boxPosition)
            {
                resultEntity.assign<Box>(box.get()->getColor());
            }
        }
    });
}

