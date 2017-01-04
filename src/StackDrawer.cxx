//
// Created by Onat Bas on 04/01/17.
//

#include "StackDrawer.hxx"
#include "BoxDrawer.hxx"
#include "WindowDimensionGetter.hxx"
#include "GameLooper.hxx"
#include <map>

DrawPosition operator+(const Dimension &d, const DrawPosition &p)
{
    return DrawPosition(d.getWidth() + p.getX(), d.getHeight() + p.getY());
}

std::string operator<<(std::string s, const char *rhs) {
    s.append(std::string(rhs));
    return s;
}

void StackDrawer::draw(const Stack &stack) {
    stacks.push_back(&stack);
}

void StackDrawer::drawAll()
{
    WindowDimensionGetter getter;
    Dimension windowDimensions  = getter.getDimensionsOfWindows(window);
    for (const Stack *s : stacks){
        const Stack &stack = *s;
        const int size = stack.size();
        for (int i = 0; i < size; i++) {
            const std::string path = getBoxPath(stack[i]);
            BoxDrawer *drawer = getDrawer(path);
            const bool success = drawer->drawAt(window, stack[i], DrawPosition(0, windowDimensions.getHeight() - (size-i) * 70));
        }
    }
}

BoxDrawer *StackDrawer::getDrawer(const std::string drawerPath) {
    static std::map<std::string, std::shared_ptr<BoxDrawer> > bowDrawers;
    if (bowDrawers[drawerPath] == nullptr)
        bowDrawers[drawerPath] = std::make_shared<BoxDrawer>(drawerPath);
    return bowDrawers[drawerPath].get();
}

StackDrawer::StackDrawer(Window *window, GameLooper &looper) : window(window) {
    looper.observe(BOXESEVENT_ENTER_FRAME, 0, [&](SDL_Event){
        drawAll();
    });
}

const std::string StackDrawer::getBoxPath(const Box &box) {

    switch (box.getColor()) {
        case GREEN:
            return getMaterialsPath() << "alienGreen_square.png";
        case BLUE:
            return getMaterialsPath() << "alienBlue_square.png";
        case RED:
            return getMaterialsPath() << "alienPink_square.png";
    }
    return "";
}

std::string StackDrawer::getMaterialsPath() const {
    return "boxesGame_tests_materials/";
}
