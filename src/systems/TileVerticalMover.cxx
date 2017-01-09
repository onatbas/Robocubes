//
// Created by Onat Bas on 06/01/17.
//

#include <components/MouseClicked.hxx>
#include <logic/AdjacentPopper.hxx>
#include <logic/VerticalMover.hxx>
#include <view/BoxDrawingConfiguration.hxx>
#include <components/Scale.hxx>
#include "TileVerticalMover.hxx"
#include "components/Offset.hxx"
#include "logic/StackSetInserter.hxx"
#include "GameLooper.hxx"
#include "delegates/SquaredDistanceModeler.hxx"
#include <map>
#include <vector>

using namespace entityx;

void TileVerticalMover::update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) {

    BoxPosition clickPos(0, 0);
    if (clicked.getClick(clickPos))
        markVerticalMovingTiles(entities, clickPos);
    moveOffsets(entities, dt);
}

void TileVerticalMover::moveOffsets(entityx::EntityManager &manager, entityx::TimeDelta dt) {

    BoxDrawingConfiguration config;
    const Dimension pngDims = config.getBoxDimensions();
    const Scale pngScale = config.getBoxFinalScale();

    bool allMoved = true;
    manager.each<Offset, VerticalMovement, BoxPosition>(
            [&](Entity entity, Offset &offset, VerticalMovement &movement, BoxPosition &boxPosition) {
                allMoved = false;
                float totalDistanceToTravel = movement.getMoveByUnit() * pngDims.getHeight() * pngScale.scale;
                float totalMovementDuration = 200 + (movement.getCurrentHeight() - movement.getMoveByUnit()) * 60;

                // Distance travelled is x^2. Modelling that.
                SquaredDistanceModeler modeler(totalDistanceToTravel, totalMovementDuration);
                int shouldBeInPlace = modeler.getAfterTravelByTime(-offset.getY(), 10);
                offset.setY(-shouldBeInPlace);

                if (std::abs(shouldBeInPlace > totalDistanceToTravel)) {
                    int columnOrder = boxPosition.getX();
                    entity.remove<BoxPosition>();
                    entity.remove<Offset>();
                    entity.remove<VerticalMovement>();
                    entity.assign<BoxPosition>(columnOrder, movement.getCurrentHeight() - movement.getMoveByUnit());
                    entity.assign<Offset>();
                }

            });
    if (allMoved) {
        StackSet updated;
        StackSetInserter inserter(updated);
        manager.each<BoxPosition, Box>([&](Entity entity, BoxPosition &position, Box &b) {
            inserter.insert(position, b);
        });

        looper.sendSignal(BOXESEVENT_CHECK_HORIZONTAL_SLIDE, 0, 0);
        set = updated;
    }
}

void TileVerticalMover::markVerticalMovingTiles(entityx::EntityManager &entities, BoxPosition &clicked) {

    AdjacentPopper popper;
    AdjacentPopperResult result = popper.pop(set, clicked);
    VerticalMover mover;
    VerticalMovements movements = mover.move(set, result);

    std::map<BoxPosition, VerticalMovement> movementsMap;
    {
        const std::vector<StackOrder> vector = movements.getStackOrdersWhichExist();
        for (StackOrder order : vector) {
            const std::vector<VerticalMovement> &movementsInStack = movements.getMovesInStack(order);
            for (const VerticalMovement &m : movementsInStack) {
                movementsMap[BoxPosition(order, m.getCurrentHeight())] = m;
            }
        }
    }

    entities.each<BoxPosition>([&](Entity e, BoxPosition &position) {
        if (movementsMap.find(position) != movementsMap.end()) {
            const auto &m = movementsMap[position];
            if (m.getMoveByUnit() > 0 && m.getCurrentHeight() == position.getY()) {
                e.assign_from_copy(m);
            }
        }
    });

    looper.sendSignal(BOXESEVENT_VERTICAL_MOVEMENTS_APPLIED, 0, (char *) &movements);
}

TileVerticalMover::TileVerticalMover(StackSet &set, GameLooper &looper) : set(set),
                                                                          looper(looper) {
    looper.observe(BOXESEVENT_BOX_CLICKED, 0, [&](const char *data) {
        clicked = *(BoxPosition *) data;
    });
}
