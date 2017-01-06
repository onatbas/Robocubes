//
// Created by Onat Bas on 02/01/17.
//

#ifndef BOXESGAME_VERTICALMOVEMENT_HXX
#define BOXESGAME_VERTICALMOVEMENT_HXX

class VerticalMovement {

public:
    VerticalMovement(int currentHeight, int moveByUnit);
    bool operator==(const VerticalMovement &rhs) const;
    bool operator!=(const VerticalMovement &rhs) const;

    int getCurrentHeight() const;
    int getMoveByUnit() const;
protected:
    int currentHeight;
    int moveByUnit;
public:
    VerticalMovement();
};

#endif //BOXESGAME_VERTICALMOVEMENT_HXX
