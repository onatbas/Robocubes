//
// Created by Onat Bas on 05/01/17.
//

#include "BoxPositionCalculator.hxx"
#include "Dimension.hxx"
#include "Scale.hxx"
#include "BoxDrawingConfiguration.hxx"
#include <iostream>

const Dimension &box = Dimension(169, 149);

BoxPosition
BoxPositionCalculator::clickToBox(const DrawPosition &position, Dimension windowDimensions) const {
    // Cast down to int is intentional.
    BoxDrawingConfiguration config;
    Scale scale = config.getBoxFinalScale();

    const int i = (float)position.getX() / box.getWidth() / scale.scale;
    const int j = -(float)(position.getY() + 90 - windowDimensions.getHeight()) / (box.getHeight() * scale.scale);

    std::cout << "Box position : " << i << ", " << j << std::endl;

    return BoxPosition(i,j);
}

DrawPosition
BoxPositionCalculator::boxToDrawing(const BoxPosition &position, Dimension windowDimensions, Scale scale) const {
    const float x = position.getX() * box.getWidth() * scale.scale;
    const float y = windowDimensions.getHeight() - ((position.getY()+1) * box.getHeight() * scale.scale) - 90;
    DrawPosition drawPosition(x, y);

    return drawPosition;
}
