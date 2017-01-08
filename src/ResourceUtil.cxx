//
// Created by Onat Bas on 05/01/17.
//

#include "ResourceUtil.hxx"
#include <random>

std::string operator<<(std::string ss, const char *c) {
    ss.append(std::string(c));
    return ss;
}

std::string operator<<(std::string ss, int c) {
    ss.append(std::to_string(c));
    return ss;
}

std::string ResourceUtil::getMaterialsPath() const {
    return "boxesGame_tests_materials/";
}

std::string ResourceUtil::getBoxPath(const Box &box, bool alternative) const {
    switch (box.getColor()) {
        case GREEN:
            return getMaterialsPath()
                    << (alternative ? "robot_greenDrive1.png" : "robot_greenDrive2.png"); //<< "alienGreen_square.png";
        case BLUE:
            return getMaterialsPath()
                    << (alternative ? "robot_blueDrive1.png" : "robot_blueDrive2.png"); //<< "alienBlue_square.png";
        case RED:
            return getMaterialsPath()
                    << (alternative ? "robot_redDrive1.png" : "robot_redDrive2.png"); //"alienPink_square.png";
        case YELLOW:
            return getMaterialsPath()
                    << (alternative ? "robot_yellowDrive1.png" : "robot_yellowDrive2.png");
    }
    return "";
}

std::string ResourceUtil::getTerrainPath() const {
    return getMaterialsPath() << "terrain.png";
}

std::string ResourceUtil::getBackgroundPath() const {
    return getMaterialsPath() << "colored_grass.png";
}

std::string ResourceUtil::getRandomSmoke() const {
    int random = int(std::rand() / (float) RAND_MAX * 10.0); // random number of 0-9
    return getMaterialsPath() << "whitePuff0" << random << ".png";
}

int ResourceUtil::getSmokeSize() const {
  return 5;
}

std::string ResourceUtil::getSmokeNew(int i) const {
    return getMaterialsPath() << "puf" << i+1 << ".png";
}

std::string ResourceUtil::getLogoPath() {
    return getMaterialsPath() << "logo.png";
}

const std::string ResourceUtil::getStartPath() {
    return getMaterialsPath() << "start.png";
}

std::string ResourceUtil::getMusicPath() {
    return getMaterialsPath() << "mainloop.wav";
}

std::string ResourceUtil::getSoundLevelBegin() {
    return getMaterialsPath() << "drums.wav";
}

std::string ResourceUtil::getClickedSound() {
    return getMaterialsPath() << "pop.wav";

}

std::string ResourceUtil::getBoardPath() {
    return getMaterialsPath() << "board.png";
}

std::string ResourceUtil::getTTFPath() {
    return getMaterialsPath() << "font.ttf";
}

