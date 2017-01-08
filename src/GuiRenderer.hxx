//
// Created by Onat Bas on 08/01/17.
//

#ifndef BOXESGAME_GUIRENDERER_HXX
#define BOXESGAME_GUIRENDERER_HXX

#include "EntityFactory.hxx"
#include "GameSystem.hxx"
#include "Dimension.hxx"
#include "GameLooper.hxx"
#include "DrawPosition.hxx"
#include "TTFText.hxx"

class GuiRenderer : public GameSystem<GuiRenderer>{
public:
    virtual void
    update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) override;
public:
    GuiRenderer(EntityFactory *factory, Dimension windowDimension, GameLooper *looper);
private:

    EntityFactory *factory;
    Dimension windowDimension;
    GameLooper *looper;

    entityx::Entity scoreEntity;
    DrawPosition createBoard(EntityFactory *factory, Dimension windowDimension) const;
    DrawPosition createScoreEntity(EntityFactory *factory, DrawPosition boardPosition);
    void updateScoreText(int count);
    int getCurrentPoint();
    void updateTextToEndGame();
};

#endif //BOXESGAME_GUIRENDERER_HXX
