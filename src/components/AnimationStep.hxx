//
// Created by Onat Bas on 06/01/17.
//

#ifndef BOXESGAME_ANIMATIONSTEP_HXX
#define BOXESGAME_ANIMATIONSTEP_HXX

#include <string>
#include "Scale.hxx"

class AnimationStep {
public:
    AnimationStep();
    AnimationStep(const std::string &nextPath);
    AnimationStep(std::string path, Scale scale);
    bool isNextStepValid() const;
    std::string getPath() const;
    Scale getScale() const;
private:
    std::string nextPath;
    Scale scale;
};

#endif //BOXESGAME_ANIMATIONSTEP_HXX
