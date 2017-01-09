//
// Created by Onat Bas on 05/01/17.
//

#include "StackSetEntityMaker.hxx"
#include "BoxDrawingConfiguration.hxx"

double BoxDrawingConfiguration::getBoxFinalScale() const {
    return 0.5;
}

double BoxDrawingConfiguration::getBoxScaleFactor() const {
    return 0.25;
}

Dimension BoxDrawingConfiguration::getBoxDimensions() const {
    return Dimension(169, 149);
}
