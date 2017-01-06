//
// Created by Onat Bas on 06/01/17.
//

#ifndef BOXESGAME_ANIMATIONSET_HXX
#define BOXESGAME_ANIMATIONSET_HXX

#include <vector>
#include <Scale.hxx>
#include "AnimationStep.hxx"

class AnimationSet {

public:
    void setPassInterval(double interval);
    void setOneShot(bool oneShot);
    void addSprite(std::string path, Scale scale);
    AnimationStep getNext(double timeDelta);

private:
    std::vector<std::string> spritePaths;
    std::vector<Scale> scales;

    double interval;
    double passedTime;
    bool oneShot;

    double getTotalAnimationLength() const;
    bool ifOneShotAnimationEnds() const;
    int getNextPathIndex();
};

#endif //BOXESGAME_ANIMATIONSET_HXX
