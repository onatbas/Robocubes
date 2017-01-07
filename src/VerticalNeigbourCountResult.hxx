//
// Created by Onat Bas on 01/01/17.
//

#ifndef BOXESGAME_NEIGBOURCOUNTRESULT_HXX
#define BOXESGAME_NEIGBOURCOUNTRESULT_HXX

class VerticalNeigbourCountResult {
private:
    int upperNeighbours;
    int lowerNeighbours;

public:
    VerticalNeigbourCountResult(int upperNeighbours, int lowerNeighbours);
    int getSameColorAreaCount() const;
    int getUpperNeighbours() const;
    int getLowerNeighbours() const;

};

#endif //BOXESGAME_NEIGBOURCOUNTRESULT_HXX
