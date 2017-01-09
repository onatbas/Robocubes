//
// Created by Onat Bas on 08/01/17.
//

#ifndef BOXESGAME_ANYCLICKTRACKER_HXX
#define BOXESGAME_ANYCLICKTRACKER_HXX

#include "GameLooper.hxx"

class AnyClickTracker {

private:
    GameLooper *looper;
public:
    AnyClickTracker(GameLooper *looper, std::function<void()> callback);
};

#endif //BOXESGAME_ANYCLICKTRACKER_HXX
