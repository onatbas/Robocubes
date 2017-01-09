//
// Created by Onat Bas on 05/01/17.
//

#ifndef BOXESGAME_GAMEBEGINZOOMOUT_HXX
#define BOXESGAME_GAMEBEGINZOOMOUT_HXX

class GameBeginZoomOut {
public:
    float getDurationToWait() const;
    float getScaleFactor() const;
    float getSetZoomTo() const;
    GameBeginZoomOut(float durationToWait, float scaleFactor, float setZoomTo);

public: // State
    float waitedDuration;
    float startedListening;
    float oldScale;

private:
    float durationToWait;
    float scaleFactor;
    float setZoomTo;
};

#endif //BOXESGAME_GAMEBEGINZOOMOUT_HXX
