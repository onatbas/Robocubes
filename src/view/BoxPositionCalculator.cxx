//
// Created by Onat Bas on 05/01/17.
//

#include "BoxPositionCalculator.hxx"
#include "components/Dimension.hxx"
#include "components/Scale.hxx"
#include "BoxDrawingConfiguration.hxx"
#include <iostream>


BoxPosition
BoxPositionCalculator::clickToBox(const DrawPosition &position, Dimension windowDimensions) const {

    BoxDrawingConfiguration config;
    Dimension box = config.getBoxDimensions();
    Scale scale = config.getBoxFinalScale();

    // Cast down to int is intentional.
    const int i = (float)position.getX() / box.getWidth() / scale.scale;
    const int j = -(float)(position.getY() + 90 - windowDimensions.getHeight()) / (box.getHeight() * scale.scale);

    return BoxPosition(i,j);
}

DrawPosition
BoxPositionCalculator::boxToDrawing(const BoxPosition &position, Dimension windowDimensions, Scale scale) const {

    BoxDrawingConfiguration config;
    Dimension box = config.getBoxDimensions();

    const float x = position.getX() * box.getWidth() * scale.scale;
    const float y = windowDimensions.getHeight() - ((position.getY()+1) * box.getHeight() * scale.scale) - 90;

    DrawPosition drawPosition(x, y);

    return drawPosition;
}
