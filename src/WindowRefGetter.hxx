//
// Created by Onat Bas on 03/01/17.
//

#ifndef BOXESGAME_WINDOWREFGETTER_HXX
#define BOXESGAME_WINDOWREFGETTER_HXX

#include <SDL2/SDL_video.h>
#include "Window.hxx"

class WindowRefGetter {
public:
    WindowRefGetter(const Window *wind);
    SDL_Window *getWindowRef() const;

private:
    const Window *window;
};

#endif //BOXESGAME_WINDOWREFGETTER_HXX
