//
// Created by Onat Bas on 02/01/17.
//

#ifndef BOXESGAME_ADJACENTPOPPERRESULT_HXX
#define BOXESGAME_ADJACENTPOPPERRESULT_HXX

#include <vector>
#include "components/BoxPosition.hxx"
#include "PoppedPositions.hxx"

class AdjacentPopperResult {
public:
    AdjacentPopperResult();
    AdjacentPopperResult(const PoppedPositions &positions);
    PoppedPositions getPopped() const;
private:
    PoppedPositions positions;
};

#endif //BOXESGAME_ADJACENTPOPPERRESULT_HXX
