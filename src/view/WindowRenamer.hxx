//
// Created by Onat Bas on 03/01/17.
//

#ifndef BOXESGAME_WINDOWRENAMER_HXX
#define BOXESGAME_WINDOWRENAMER_HXX

#include "Window.hxx"
#include <string>

class WindowRenamer {
public:
    void rename(std::shared_ptr<Window> window, std::string name) const;
};

#endif //BOXESGAME_WINDOWRENAMER_HXX
