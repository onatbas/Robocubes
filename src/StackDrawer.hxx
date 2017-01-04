//
// Created by Onat Bas on 04/01/17.
//

#ifndef BOXESGAME_STACKRENDERER_HXX
#define BOXESGAME_STACKRENDERER_HXX
#include "Stack.hxx"
#include "Window.hxx"
#include "Box.hxx"
#include "BoxDrawer.hxx"
#include "GameLooper.hxx"

class StackDrawer {

public:
    StackDrawer(Window *window, GameLooper &looper);
    void draw(const Stack &stack);

protected:
    void drawAll();
    Window *window;
    const std::string getBoxPath(const Box &box);
    std::string getMaterialsPath() const;
    BoxDrawer * getDrawer(const std::string drawerPath);
    std::vector<const Stack *> stacks;
};

#endif //BOXESGAME_STACKRENDERER_HXX
