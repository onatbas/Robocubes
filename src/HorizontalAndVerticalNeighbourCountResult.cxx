//
// Created by Onat Bas on 01/01/17.
//

#include "HorizontalAndVerticalNeighbourCountResult.hxx"

int HorizontalAndVerticalNeighbourCountResult::getSameColorAreaCount() const {
	return neighbours;
}

HorizontalAndVerticalNeighbourCountResult::HorizontalAndVerticalNeighbourCountResult(int neighbours) : neighbours(
		neighbours) {}
