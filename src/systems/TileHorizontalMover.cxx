//
// Created by Onat Bas on 07/01/17.
//

#include <entityx/entityx.h>
#include <decorators/GameLooper.hxx>
#include <logic/AdjacentPopperResult.hxx>
#include <logic/VerticalMover.hxx>
#include <logic/HorizontalMover.hxx>
#include <components/Offset.hxx>
#include <view/BoxDrawingConfiguration.hxx>
#include <components/Scale.hxx>
#include <delegates/SquaredDistanceModeler.hxx>
#include "TileHorizontalMover.hxx"
#include "delegates/MovementChecker.hxx"

using namespace entityx;

bool operator==(const HorizontalMovement &movement, int i) {
    return movement.getStackOrder() == i;
}

TileHorizontalMover::TileHorizontalMover(StackSet &set, GameLooper &looper) : set(set),
                                                                              looper(looper),
                                                                              verticalMovesEnded(false) {
    looper.observe(BOXESEVENT_CHECK_HORIZONTAL_SLIDE, 0, [&](const char *e) {
        verticalMovesEnded = true;
    });

    looper.observe(BOXESEVENT_VERTICAL_MOVEMENTS_APPLIED, 0, [&](const char *data) {
        VerticalMovements result = *(VerticalMovements *) data;
        HorizontalMover mover;
        movements = mover.move(set, result);
    });
    looper.observe(BOXESEVENT_FORCE_HORIZONTAL_CHECK, 0, [&](const char *data){
        const EntityManager *entities_const = (EntityManager *)data;
        EntityManager *entities = const_cast<EntityManager *>(entities_const);
        update(*entities);
    });

}

void TileHorizontalMover::update(EntityManager &entities, EventManager &events, TimeDelta dt) {
    update(entities);

}

void TileHorizontalMover::update(EntityManager &entities) {

    MovementChecker checker;
    if (!checker.isSomethingMoving(entities))
    {

    HorizontalMovements moves;
    if (movements.getClick(moves)) {
        std::__1::map<int, HorizontalMovement> orders;
        int size = moves.getMovementsSize();
        for (int i = 0; i < size; i++) {
            const HorizontalMovement &movement = moves.getMovementAt(i);
            orders[movement.getStackOrder()] = movement;
        }

        entities.each<BoxPosition>([&](Entity entity, BoxPosition &position) {
            if (orders.find(position.getX()) != orders.end())
            {
                auto move = orders[position.getX()];
                if (move.getSlideBy() != 0)
                    entity.assign_from_copy(move);
            }
        });
    }
    }


    entities.each<BoxPosition, HorizontalMovement, Offset>([&](Entity entity, BoxPosition &position, HorizontalMovement &movement, Offset &offset){
        BoxDrawingConfiguration config;
        const Dimension pngDims = config.getBoxDimensions();
        const Scale pngScale = config.getBoxFinalScale();

        float totalDistanceToTravel = movement.getSlideBy() * pngDims.getHeight() * pngScale.scale;
        float totalMovementDuration = 200 + (position.getX()-movement.getSlideBy()) * 60;

        SquaredDistanceModeler modeler(totalDistanceToTravel, totalMovementDuration);
        int shouldBeInPlace = modeler.getAfterTravelByTime(offset.getX(), 10);

        offset.setX(shouldBeInPlace);
        if (std::abs(shouldBeInPlace) > std::abs(totalDistanceToTravel))
        {
            offset = Offset();
            position = BoxPosition(movement.getStackOrder() - movement.getSlideBy(), position.getY());
            entity.remove<HorizontalMovement>();
        }
    });
}

