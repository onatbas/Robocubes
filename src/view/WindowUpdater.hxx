//
// Created by Onat Bas on 03/01/17.
//

#ifndef BOXESGAME_WINDOWUPDATER_HXX
#define BOXESGAME_WINDOWUPDATER_HXX

#include "Window.hxx"
#include "decorators/GameLooper.hxx"

class WindowUpdater {
public:
    WindowUpdater();
    WindowUpdater(GameLooper *looper, const Window *window);
    void updateWindow(const Window *window) const;
};

#endif //BOXESGAME_WINDOWUPDATER_HXX
