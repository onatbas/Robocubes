//
// Created by Onat Bas on 08/01/17.
//

#include "GameOverMaker.hxx"
#include "AnimationSet.hxx"
#include "ResourceUtil.hxx"
#include "DrawPosition.hxx"
#include "BoxDrawingConfiguration.hxx"

using namespace entityx;

GameOverMaker::GameOverMaker(GameLooper *looper, EntityFactory *factory, Dimension windowDimension) : looper(looper),
                                                                                                      factory(factory) {
    endGame = false;

    looper->observe(BOXESGAME_RESET_SUCCESS, 0, [&](const char *data){
        this->endGame = false;
        if (entity.valid())
            entity.destroy();
    });

    looper->observe(BOXESGAME_ENDGAME, 0, [=](const char *data) {
        if (endGame)
            return;

        this->endGame = true;
        entity = factory->entities.create();

        ResourceUtil util;
        std::string gameOver = util.getGameOverPath();
        std::string restart = util.getStartPath();

        AnimationSet set;
        set.setPassInterval(45);
        int begin = 0.1;
        double step = 0.0085;
        double endVal = 0.15;

        for (float scale = begin; scale < endVal; scale += step) {
            set.addSprite(gameOver, scale);
        }
        for (float scale = endVal; scale > begin; scale -= step) {
            set.addSprite(gameOver, scale);
        }
        for (float scale = begin; scale < endVal; scale += step) {
            set.addSprite(restart, scale);
        }
        for (float scale = endVal; scale > begin; scale -= step) {
            set.addSprite(restart, scale);
        }

        BoxDrawingConfiguration config;
        const Dimension boxDimensions = config.getBoxDimensions();
        const double scale = config.getBoxFinalScale();

        entity.assign_from_copy(set);
        DrawPosition drawPosition = DrawPosition(windowDimension.getWidth() / 2 - boxDimensions.getWidth() / 2 * scale,
                                                 windowDimension.getHeight() / 2 -
                                                 boxDimensions.getHeight() / 2 * scale);
        entity.assign_from_copy(drawPosition);
    });

}
