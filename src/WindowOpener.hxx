//
// Created by Onat Bas on 03/01/17.
//

#ifndef BOXESGAME_WINDOWOPENER_HXX
#define BOXESGAME_WINDOWOPENER_HXX

#include "Window.hxx"
#include <memory>

class WindowOpener{
public:
    std::shared_ptr<Window> open() const;
};

#endif //BOXESGAME_WINDOWOPENER_HXX
