//
// Created by Onat Bas on 08/01/17.
//

#ifndef BOXESGAME_GRAPHICSHOLDER_HXX
#define BOXESGAME_GRAPHICSHOLDER_HXX

class GraphicsHolder {
public:
    GraphicsHolder();
    GraphicsHolder(bool index);

    bool getGraphics();

private:
    bool index;
};

#endif //BOXESGAME_GRAPHICSHOLDER_HXX
