//
// Created by Onat Bas on 01/01/17.
//

#ifndef BOXESGAME_HORIZONTALANDVERTICALNEIGHBOURCOUNTRESULT_HXX
#define BOXESGAME_HORIZONTALANDVERTICALNEIGHBOURCOUNTRESULT_HXX

class HorizontalAndVerticalNeighbourCountResult {
public:
	int getSameColorAreaCount() const;
	
private:
	int neighbours;
public:
	HorizontalAndVerticalNeighbourCountResult(int neighbours);
};

#endif //BOXESGAME_HORIZONTALANDVERTICALNEIGHBOURCOUNTRESULT_HXX
