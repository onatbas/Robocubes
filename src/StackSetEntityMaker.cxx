//
// Created by Onat Bas on 04/01/17.
//

#include "StackSetEntityMaker.hxx"
#include "BoxDrawer.hxx"
#include "WindowDimensionGetter.hxx"
#include "GameLooper.hxx"
#include "../tests/EntityFactory.hxx"
#include "StackSet.hxx"
#include <map>

std::string operator<<(std::string s, const char *rhs) {
    s.append(std::string(rhs));
    return s;
}

void StackSetEntityMaker::makeEntities(const StackSet &stack) {
}

StackSetEntityMaker::StackSetEntityMaker(EntityFactory *factory) : factory(factory) {
}


std::string getMaterialsPath() {
    return "boxesGame_tests_materials/";
}
std::string getBoxPath(const Box &box) {

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

