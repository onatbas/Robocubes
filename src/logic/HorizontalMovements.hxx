//
// Created by Onat Bas on 02/01/17.
//

#ifndef BOXESGAME_HORIZONTALMOVEMENTS_HXX
#define BOXESGAME_HORIZONTALMOVEMENTS_HXX

#include "HorizontalMovement.hxx"
#include <vector>

class HorizontalMovements {
public:
    int getMovementsSize() const;
    void addMovement(HorizontalMovement movement);

    HorizontalMovement getMovementAt(int i) const;
    HorizontalMovement operator[](int i) const;
    HorizontalMovements();
protected:
    std::vector<HorizontalMovement> movements;
};

#endif //BOXESGAME_HORIZONTALMOVEMENTS_HXX
