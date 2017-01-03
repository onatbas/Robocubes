//
// Created by Onat Bas on 02/01/17.
//

#ifndef BOXESGAME_HORIZONTALMOVEMENT_HXX
#define BOXESGAME_HORIZONTALMOVEMENT_HXX

class HorizontalMovement {

public:
    HorizontalMovement(int stackOrder, int slideBy);

    int getSlideBy() const;
    int getStackOrder() const;
    bool operator==(const HorizontalMovement &rhs) const;
    bool operator!=(const HorizontalMovement &rhs) const;
protected:
    int slideBy;
    int stackOrder;
};

#endif //BOXESGAME_HORIZONTALMOVEMENT_HXX
