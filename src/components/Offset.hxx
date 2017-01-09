//
// Created by Onat Bas on 06/01/17.
//

#ifndef BOXESGAME_OFFSET_HXX
#define BOXESGAME_OFFSET_HXX

class Offset {

    int x;
    int y;
public:
    Offset(int x, int y);
    Offset();
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
};

#endif //BOXESGAME_OFFSET_HXX
