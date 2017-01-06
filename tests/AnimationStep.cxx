//
// Created by Onat Bas on 06/01/17.
//

#include <Scale.hxx>
#include "AnimationStep.hxx"

bool AnimationStep::isNextStepValid() const {
    return (nextPath.size() != 0);
}

AnimationStep::AnimationStep() : nextPath(""), scale(1){
}

std::string AnimationStep::getPath() const {
    return nextPath;
}

AnimationStep::AnimationStep(std::string path, Scale scale) : nextPath(path), scale(scale) {

}

Scale AnimationStep::getScale() const{
    return scale;
}
