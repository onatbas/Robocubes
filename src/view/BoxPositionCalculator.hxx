//
// Created by Onat Bas on 05/01/17.
//

#ifndef BOXESGAME_BOXPOSITIONCALCULATOR_HXX
#define BOXESGAME_BOXPOSITIONCALCULATOR_HXX

#include "components/BoxPosition.hxx"
#include "components/DrawPosition.hxx"
#include "components/Dimension.hxx"
#include "components/Scale.hxx"

class BoxPositionCalculator {

public:
    DrawPosition boxToDrawing(const BoxPosition &position, Dimension windowDimensions, Scale scale) const;
    BoxPosition clickToBox(const DrawPosition &position, Dimension windowDimensions) const;
};

#endif //BOXESGAME_BOXPOSITIONCALCULATOR_HXX
