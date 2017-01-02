//
// Created by Onat Bas on 01/01/17.
//

#ifndef BOXESGAME_BOXPOSITION_HXX
#define BOXESGAME_BOXPOSITION_HXX

class BoxPosition {
	int x;
	int y;

public:
	BoxPosition(int x, int y);
	int getX() const;
	int getY() const;
	bool operator==(const BoxPosition &rhs) const;
	bool operator!=(const BoxPosition &rhs) const;
	BoxPosition operator+(const BoxPosition &rhs) const;
	
};

#endif //BOXESGAME_BOXPOSITION_HXX
