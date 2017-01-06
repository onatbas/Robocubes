//
// Created by Onat Bas on 06/01/17.
//

#ifndef BOXESGAME_WINDOWCLEANER_HXX
#define BOXESGAME_WINDOWCLEANER_HXX

#include "EntityFactory.hxx"
#include "GameSystem.hxx"
#include "Renderable.hxx"

class WindowCleaner {

public:
    void clean(Renderable &renderable, Window *window) const;
};

#endif //BOXESGAME_WINDOWCLEANER_HXX
