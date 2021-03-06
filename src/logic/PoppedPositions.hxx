//
// Created by Onat Bas on 02/01/17.
//

#ifndef BOXESGAME_POPPEDPOSITIONS_HXX
#define BOXESGAME_POPPEDPOSITIONS_HXX

#include <vector>
#include "components/BoxPosition.hxx"

class PoppedPositions {
public:
    int getSize() const;
    void popPosition(const BoxPosition &position);

    BoxPosition operator[](int i) const;

protected:
    std::vector<BoxPosition> positions;
};

#endif //BOXESGAME_POPPEDPOSITIONS_HXX
