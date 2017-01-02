//
// Created by Onat Bas on 01/01/17.
//

#ifndef BOXESGAME_HORIZONTALANDVERTICALNEIGHBOURCOUNTRESULT_HXX
#define BOXESGAME_HORIZONTALANDVERTICALNEIGHBOURCOUNTRESULT_HXX

class AdjacentNeighbourCountResult {
public:
	int getSameColorAreaCount() const;
	
private:
	int neighbours;
public:
	AdjacentNeighbourCountResult(int neighbours);
};

#endif //BOXESGAME_HORIZONTALANDVERTICALNEIGHBOURCOUNTRESULT_HXX
