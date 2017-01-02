//
// Created by Onat Bas on 01/01/17.
//

#ifndef BOXESGAME_BOX_H
#define BOXESGAME_BOX_H

#include "Colors.hxx"

class Box {
public:
	Box(Colors colors);
	bool operator==(const Box& other) const;
	Colors getColor() const;

private:
	Colors color;
};

#endif //BOXESGAME_BOX_H
