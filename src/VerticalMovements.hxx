//
// Created by Onat Bas on 02/01/17.
//

#ifndef BOXESGAME_VERTICALMOVEMENTS_HXX
#define BOXESGAME_VERTICALMOVEMENTS_HXX

typedef int StackOrder;
#include <map>
#include <vector>
#include "VerticalMovement.hxx"
#include "BoxPosition.hxx"

class VerticalMovements {
public:
    int getStackSize() const;
    int getMoveSizeInStack(int i);
    void addMovement(const BoxPosition &position, int moveDownBy);
    std::vector<VerticalMovement> getMovesInStack(int i);
    std::vector<StackOrder> getStackOrdersWhichExist();

protected:
    std::map<StackOrder, std::vector<VerticalMovement>> movements;
};

#endif //BOXESGAME_VERTICALMOVEMENTS_HXX
