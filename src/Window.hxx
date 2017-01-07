//
// Created by Onat Bas on 03/01/17.
//

#ifndef BOXESGAME_WINDOW_HXX
#define BOXESGAME_WINDOW_HXX

#include <SDL2/SDL.h>

class Window {

public:
    Window(SDL_Window *pWindow);
    ~Window();

    bool is_open() const;

private:
    friend class WindowRefGetter;
    SDL_Window *pWindow;
};

#endif //BOXESGAME_WINDOW_HXX
