//
// Created by Onat Bas on 02/01/17.
//

#include <StackSet.hxx>
#include "AdjacentPopperResult.hxx"


AdjacentPopperResult::AdjacentPopperResult(const PoppedPositions &positions) : positions(positions) {

}

PoppedPositions AdjacentPopperResult::getPopped() const {
    return positions;
}

AdjacentPopperResult::AdjacentPopperResult() {

}
