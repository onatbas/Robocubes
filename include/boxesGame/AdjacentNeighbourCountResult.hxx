//
// Created by Onat Bas on 01/01/17.
//

#ifndef BOXESGAME_HORIZONTALANDVERTICALNEIGHBOURCOUNTRESULT_HXX
#define BOXESGAME_HORIZONTALANDVERTICALNEIGHBOURCOUNTRESULT_HXX

#include <vector>
#include "BoxPosition.hxx"

class AdjacentNeighbourCountResult {
public:
    int getSameColorAreaCount() const;
    BoxPosition getNeighbourAt(int i) const;
    BoxPosition operator[](int i) const;

protected:
    friend class AdjacentNeighbourCounter;
    std::vector<BoxPosition> neighbours;

};

#endif //BOXESGAME_HORIZONTALANDVERTICALNEIGHBOURCOUNTRESULT_HXX
