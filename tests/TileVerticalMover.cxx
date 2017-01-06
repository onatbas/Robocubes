//
// Created by Onat Bas on 06/01/17.
//

#include <MouseClicked.hxx>
#include <AdjacentPopper.hxx>
#include <VerticalMover.hxx>
#include <BoxDrawingConfiguration.hxx>
#include <Scale.hxx>
#include "TileVerticalMover.hxx"
#include "Offset.hxx"
#include "StackSetInserter.hxx"
#include <map>
#include <vector>

using namespace entityx;

void TileVerticalMover::update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) {
    markVerticalMovingTiles(entities);
    moveOffsets(entities, dt);
}


void TileVerticalMover::moveOffsets(entityx::EntityManager &manager, entityx::TimeDelta dt) {

    BoxDrawingConfiguration config;
    const Dimension pngDims = config.getBoxDimensions();
    const Scale pngScale = config.getBoxFinalScale();

    bool allMoved = true;
    manager.each<Offset, VerticalMovement, BoxPosition>([&](Entity entity, Offset &offset, VerticalMovement &movement, BoxPosition &boxPosition){
        allMoved = false;
        float totalDistanceToTravel = movement.getMoveByUnit() * pngDims.getHeight() * pngScale.scale;
        float totalMovementDuration = 200 + (movement.getCurrentHeight()-movement.getMoveByUnit()) * 60;

        // Distance travelled is x^2. Modelling that.
        const float scalingFactorOfX2 = totalDistanceToTravel / (totalMovementDuration * totalMovementDuration);
        const float travelledSoFar = -offset.getY();
        const float travelledTime = std::sqrt( travelledSoFar / scalingFactorOfX2 );
        const float travelTimeAdded = travelledTime + dt;
        const float shouldBeInPlace = scalingFactorOfX2 * (travelTimeAdded * travelTimeAdded) + 1;
        offset.setY(-shouldBeInPlace);

        if (std::abs(shouldBeInPlace > totalDistanceToTravel))
        {
            int columnOrder = boxPosition.getX();
            entity.remove<BoxPosition>();
            entity.remove<Offset>();
            entity.remove<VerticalMovement>();
            entity.assign<BoxPosition>(columnOrder, movement.getCurrentHeight() - movement.getMoveByUnit());
            entity.assign<Offset>();
        }

    });
    if (allMoved)
    {
        StackSet updated;
        StackSetInserter inserter(updated);
        manager.each<BoxPosition, Box>([&](Entity entity, BoxPosition &position, Box &b){
            inserter.insert(position, b);
        });
        set = updated;
    }
}

void TileVerticalMover::markVerticalMovingTiles(entityx::EntityManager &entities)
{
    BoxPosition clicked(0,0);
    bool found = false;
    entities.each<MouseClicked, BoxPosition>([&](Entity entity, MouseClicked &clicked_tmp, BoxPosition &position){
        clicked = position;
        found = true;
    });

    if (!found) return;

    AdjacentPopper popper;
    AdjacentPopperResult result = popper.pop(set, clicked);
    VerticalMover mover;
    VerticalMovements movements = mover.move(set, result);

    std::map<BoxPosition, VerticalMovement > movementsMap;
    {
        const std::vector<StackOrder> vector = movements.getStackOrdersWhichExist();
        for (StackOrder order : vector) {
            const std::vector<VerticalMovement> &movementsInStack = movements.getMovesInStack(order);
            for (const VerticalMovement &m : movementsInStack) {
                movementsMap[BoxPosition(order, m.getCurrentHeight())] = m;
            }
        }
    }

    entities.each<BoxPosition>([&](Entity e, BoxPosition &position){
        if (movementsMap.find(position) != movementsMap.end())
        {
            const auto &m = movementsMap[position];
            if (m.getMoveByUnit() > 0 && m.getCurrentHeight() == position.getY())
            {
                e.assign_from_copy(m);
            }
        }
    });
}

TileVerticalMover::TileVerticalMover(StackSet &set) : set(set) {
}
