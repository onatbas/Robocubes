//
// Created by Onat Bas on 06/01/17.
//

#include "systems/RenderingSystem.hxx"
#include "PNGLoader.hxx"

std::map<std::string, std::shared_ptr<PNG> > pngs;

PNGFactory::PNGFactory(Window *window) : window(window) {
}

PNG *PNGFactory::getPNG(std::string path) {

    if (pngs[path] == nullptr) {
        PNGLoader loader;
        pngs[path] = std::make_shared<PNG>(loader.load(path, window));
    }
    return pngs[path].get();
}