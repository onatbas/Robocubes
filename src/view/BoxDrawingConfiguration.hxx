//
// Created by Onat Bas on 05/01/17.
//

#ifndef BOXESGAME_BOXDRAWINGCONFIGURATION_HXX
#define BOXESGAME_BOXDRAWINGCONFIGURATION_HXX

#include "components/Dimension.hxx"

class BoxDrawingConfiguration {
public:
    double getBoxFinalScale() const;
    double getBoxScaleFactor() const;
    Dimension getBoxDimensions() const;
};

#endif //BOXESGAME_BOXDRAWINGCONFIGURATION_HXX
