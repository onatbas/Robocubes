//
// Created by Onat Bas on 08/01/17.
//

#include "FontRenderingSubSystem.hxx"
#include "TTFText.hxx"
#include "ResourceUtil.hxx"
#include "TTFRenderer.hxx"
#include "BoxDrawingConfiguration.hxx"

using namespace entityx;

void FontRenderingSubSystem::render(entityx::EntityManager &entities, Renderable &renderable, Window *window,
                                    entityx::TimeDelta delta) {
    entities.each<DrawPosition, TTFText>([&](Entity entity, DrawPosition &position, TTFText &text){
        TTFRenderer renderer(&renderable, gFont);

        BoxDrawingConfiguration config;

        const Dimension &dimension = config.getBoxDimensions();
        double boxScale = config.getBoxFinalScale();
      //  DrawPosition offsetted(position.getX() - dimension.getWidth() / 2.0 * boxScale,
       //                        position.getY() - dimension.getHeight() / 2.0 * boxScale);

        renderer.draw(text.getText(), position);
    });
}

FontRenderingSubSystem::FontRenderingSubSystem() {
    success = true;
    if( TTF_Init() == -1 )
    {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }

    ResourceUtil util;
    gFont = TTF_OpenFont( util.getTTFPath().c_str() , 40 );
}

FontRenderingSubSystem::~FontRenderingSubSystem() {
    TTF_CloseFont(gFont);
}
