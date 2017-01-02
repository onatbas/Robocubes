//
// Created by Onat Bas on 02/01/17.
//

#ifndef BOXESGAME_POPPEDPOSITIONS_HXX
#define BOXESGAME_POPPEDPOSITIONS_HXX

#include <vector>
#include "BoxPosition.hxx"

class PoppedPositions {
public:
    int getSize() const;
    void popPosition(const BoxPosition &position);

protected:
    std::vector<BoxPosition> positions;
};

#endif //BOXESGAME_POPPEDPOSITIONS_HXX
