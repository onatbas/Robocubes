//
// Created by Onat Bas on 08/01/17.
//

#include "SoundSystem.hxx"
#include "Sound.hxx"
#include "Music.hxx"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>

using namespace entityx;

void SoundSystem::update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) {

    static Mix_Music *gMusic = NULL;


    entities.each<Sound>([&](Entity entity, Sound &sound){
        if (!sound.isLoaded()) {
            sound.setChunk(Mix_LoadWAV(sound.getWavPath().c_str()));
            Mix_Chunk *pChunk = sound.getChunk();
            Mix_PlayChannel( -1, pChunk, 0 );
        }

    });
    if (gMusic == NULL) {

        entities.each<Music>([&](Entity entity, Music &music) {
            if (gMusic == NULL) {
                gMusic = Mix_LoadMUS(music.getWavPath().c_str());
                if (gMusic == NULL) {
                    printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
                }
            }
        });
    }else
    {
        if( Mix_PlayingMusic() == 0 )

            Mix_PlayMusic( gMusic, -1 );
    }
}

SoundSystem::SoundSystem() {
    success = true;
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

}
