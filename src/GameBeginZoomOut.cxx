//
// Created by Onat Bas on 05/01/17.
//

#include "GameBeginZoomOut.hxx"

GameBeginZoomOut::GameBeginZoomOut(float durationToWait, float scaleFactor, float setZoomTo)
        : durationToWait(durationToWait), scaleFactor(scaleFactor),setZoomTo(setZoomTo) {
    waitedDuration = 0;
     startedListening = 0;
}

float GameBeginZoomOut::getDurationToWait() const {
    return durationToWait;
}

float GameBeginZoomOut::getScaleFactor() const {
    return scaleFactor;
}

float GameBeginZoomOut::getSetZoomTo() const {
    return setZoomTo;
}
