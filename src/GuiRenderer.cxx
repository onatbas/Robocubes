//
// Created by Onat Bas on 08/01/17.
//

#include "GuiRenderer.hxx"
#include "Dimension.hxx"
#include "AnimationSet.hxx"
#include "ResourceUtil.hxx"
#include "DrawPosition.hxx"
#include "BoxPosition.hxx"
#include <sstream>

using namespace entityx;

GuiRenderer::GuiRenderer(EntityFactory *factory, Dimension windowDimension, GameLooper *looper)
        : factory(factory) , windowDimension(windowDimension), looper(looper){
    looper->observe(BOXESGAME_POPPED_TILES, 0, [&](const char *data){
        const auto *neighbours = (std::vector<BoxPosition> *)data;
        const int count = neighbours->size();
        updateScoreText(count);
    });

    const DrawPosition boardPosition = createBoard(factory, windowDimension);
    const DrawPosition scorePosition = createScoreEntity(factory, boardPosition);

}

void GuiRenderer::updateScoreText(int count) {
    auto handle = scoreEntity.component<TTFText>();

    int currentPoint;
    {
        std::string current = handle->getText();
        std::stringstream ss(current);
        ss >> current >> currentPoint;
    }
    std::stringstream ss;
    ss << "Score: ";
    ss << currentPoint + count * count;
    handle->setText(ss.str());
}

DrawPosition GuiRenderer::createScoreEntity(EntityFactory *factory, DrawPosition boardPosition) {
    const DrawPosition scorePosition = DrawPosition(boardPosition.getX()-130, boardPosition.getY()-50);

    scoreEntity = factory->entities.create();
    scoreEntity.assign<TTFText>("Score: 0");
    scoreEntity.assign_from_copy(scorePosition);
    return scorePosition;
}

DrawPosition GuiRenderer::createBoard(EntityFactory *factory, Dimension windowDimension) const {
    ResourceUtil util;
    Entity entity = factory->entities.create();
    AnimationSet set;
    set.addSprite(util.getBoardPath(), 1);
    DrawPosition position(windowDimension.getWidth() - 300, 100);
    entity.assign_from_copy(set);
    entity.assign_from_copy(position);
    return position;
}

void GuiRenderer::update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) {
    
}
