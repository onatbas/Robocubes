//
// Created by Onat Bas on 07/01/17.
//

#ifndef BOXESGAME_SQUAREDDISTANCEMODELER_HXX
#define BOXESGAME_SQUAREDDISTANCEMODELER_HXX

class SquaredDistanceModeler {

public:
    SquaredDistanceModeler(float distance, float totalDuration);
    int getAfterTravelByTime(int currentPlace, int timetoTravel);
private:
    float distance;
    float totalDuration;
};

#endif //BOXESGAME_SQUAREDDISTANCEMODELER_HXX
