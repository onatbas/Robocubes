//
// Created by Onat Bas on 04/01/17.
//

#ifndef BOXESGAME_WINDOWDIMENSIONGETTER_HXX
#define BOXESGAME_WINDOWDIMENSIONGETTER_HXX

#include <components/Dimension.hxx>
#include "Window.hxx"
class WindowDimensionGetter {
public:
    Dimension getDimensionsOfWindows(const Window *window) const;
};

#endif //BOXESGAME_WINDOWDIMENSIONGETTER_HXX
