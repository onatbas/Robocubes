//
// Created by Onat Bas on 07/01/17.
//

#include <logic/NeighboursInVicinityCounter.hxx>
#include <logic/AdjacentNeighbourCounter.hxx>
#include "StackInsertionSystem.hxx"
#include "logic/HorizontalMovement.hxx"
#include "logic/StackSetInserter.hxx"
#include "logic/StackFactory.hxx"
#include "GameConfig.hxx"
#include "view/StackSetEntityMaker.hxx"
#include "components/Offset.hxx"
#include "view/GraphicsHolder.hxx"

using namespace entityx;

StackInsertionSystem::StackInsertionSystem(StackSet &set, GameLooper &looper, int roundsForInsertion) : set(set),
                                                                                                        looper(looper),
                                                                                                        roundsForInsertion(
                                                                                                                roundsForInsertion),
                                                                                                        shouldInsert(false)
{
    looper.observe(BOXESEVENT_BOX_CLICKED, 0, [&](const char *data){
        lastClick = *(BoxPosition *)data;
    });
}

void
StackInsertionSystem::update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) {
    checkShouldInsert();
    insertNewColumn(entities);
}

void StackInsertionSystem::checkShouldInsert() {
    BoxPosition click;
    if (lastClick.getClick(click))
    {
        AdjacentNeighbourCounter counter;
        if (counter.count(set, click).getSameColorAreaCount() > 1)
            shouldInsert = ((++currentRound % roundsForInsertion) == 0);
    }
}

void StackInsertionSystem::insertNewColumn(EntityManager &entities) {
    if (shouldInsert)
        {
            looper.sendSignal(BOXESEVENT_FORCE_HORIZONTAL_CHECK, 0, (char *)&entities);

            MovementChecker checker;
            bool somethingMoving = checker.isSomethingMoving(entities);

            //If nothnig is moving, then do insertion.
            if (!somethingMoving)
            {
                StackSetInserter inserter(set);
                StackFactory factory;
                GameConfig config;
                const std::__1::string choices = config.getChoices();
                int rowCount = config.getRowCount();
                Stack generated = factory.createFrom(choices, rowCount);
                inserter.insertStackToBegin(generated);


                entities.each<BoxPosition>([&](Entity entity, BoxPosition &position){
                    entity.assign<HorizontalMovement>(position.getX(), -1);
                });

                BoxDrawingConfiguration drawingConfiguration;
                for (int i=0; i<rowCount; i++)
                {
                    HorizontalMovement movement(-1, -1);
                    Entity entity = entities.create();
                    entity.assign<BoxPosition>(-1, i);
                    entity.assign_from_copy<Box>(generated[i]);
                    entity.assign<GraphicsHolder>();
                    entity.assign_from_copy(movement);
                    entity.assign<Offset>(0, 0);
                    entity.assign<Scale>(drawingConfiguration.getBoxFinalScale());

                }

                shouldInsert = false;
            }
        }
}

