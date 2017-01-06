//
// Created by Onat Bas on 06/01/17.
//

#ifndef BOXESGAME_ANIMATIONSET_HXX
#define BOXESGAME_ANIMATIONSET_HXX

class AnimationSet {

public:
    void setPassInterval(int interval);
    void setOneShot(bool oneShot);
    void addSprite(std::string path);
};

#endif //BOXESGAME_ANIMATIONSET_HXX
