//
// Created by Onat Bas on 05/01/17.
//

#ifndef BOXESGAME_MOUSECLICKED_HXX
#define BOXESGAME_MOUSECLICKED_HXX

#include "BoxPosition.hxx"

class MouseClicked {

private:
    BoxPosition position;
public:
    const BoxPosition &getPosition() const;
public:
    MouseClicked(const BoxPosition &position);
};

#endif //BOXESGAME_MOUSECLICKED_HXX
