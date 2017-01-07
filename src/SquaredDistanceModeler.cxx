//
// Created by Onat Bas on 07/01/17.
//

#include "SquaredDistanceModeler.hxx"
#include <cmath>

SquaredDistanceModeler::SquaredDistanceModeler(float distance, float totalDuration) : distance(distance),
                                                                                      totalDuration(totalDuration) {
}

int SquaredDistanceModeler::getAfterTravelByTime(int currentPlace, int timetoTravel) {
    const float scalingFactorOfX2 = distance / (totalDuration * totalDuration);
    const float travelledSoFar = currentPlace;
    const float travelledTime = std::sqrtf( travelledSoFar / scalingFactorOfX2 );
    const float travelTimeAdded = travelledTime + timetoTravel;
    const float shouldBeInPlace = scalingFactorOfX2 * (travelTimeAdded * travelTimeAdded) + 1;
    return shouldBeInPlace;
}
