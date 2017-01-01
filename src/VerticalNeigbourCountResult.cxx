//
// Created by Onat Bas on 01/01/17.
//

#include "VerticalNeigbourCountResult.hxx"

int VerticalNeigbourCountResult::getUpperNeighbours() const {
	return upperNeighbours;
}

int VerticalNeigbourCountResult::getLowerNeighbours() const {
	return lowerNeighbours;
}

VerticalNeigbourCountResult::VerticalNeigbourCountResult(int upperNeighbours, int lowerNeighbours) : upperNeighbours(upperNeighbours),
																					 lowerNeighbours(lowerNeighbours) {}

int VerticalNeigbourCountResult::getSameColorAreaCount() const {
	return getUpperNeighbours() + getLowerNeighbours() + 1;
}
