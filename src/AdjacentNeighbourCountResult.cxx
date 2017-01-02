//
// Created by Onat Bas on 01/01/17.
//

#include "AdjacentNeighbourCountResult.hxx"

int AdjacentNeighbourCountResult::getSameColorAreaCount() const {
	return neighbours;
}

AdjacentNeighbourCountResult::AdjacentNeighbourCountResult(int neighbours) : neighbours(
		neighbours) {}
