//
// Created by Onat Bas on 03/01/17.
//

#ifndef BOXESGAME_DIMENSIONCALCULATOR_HXX
#define BOXESGAME_DIMENSIONCALCULATOR_HXX

#include "Dimension.hxx"
#include "PNG.hxx"

class PNGDimensionGetter {

public:
    Dimension calculate(const PNG &png) const;
};

#endif //BOXESGAME_DIMENSIONCALCULATOR_HXX
