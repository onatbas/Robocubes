//
// Created by Onat Bas on 06/01/17.
//

#include <string>
#include <Scale.hxx>
#include "AnimationSet.hxx"

void AnimationSet::setPassInterval(double interval) {
    this->interval = interval;
}

void AnimationSet::setOneShot(bool oneShot) {
    this->oneShot = oneShot;
}

void AnimationSet::addSprite(std::string path, Scale scale) {
    spritePaths.push_back(path);
    scales.push_back(scale);
}

AnimationStep AnimationSet::getNext(double timeDelta) {
    passedTime += timeDelta;

    if (ifOneShotAnimationEnds())
        return AnimationStep();

    int index = getNextPathIndex();
    return AnimationStep(spritePaths[index], scales[index]);
}

bool AnimationSet::ifOneShotAnimationEnds() const {
    return oneShot && passedTime >= getTotalAnimationLength();
}

double AnimationSet::getTotalAnimationLength() const {
    return spritePaths.size() * interval;
}

int AnimationSet::getNextPathIndex() {
    int howManyIntervals = passedTime / (float) interval;
    int whichFrameToRender = howManyIntervals % spritePaths.size();
    return whichFrameToRender;
}
