#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include "Renderer.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("No se pudo inicializar SDL: %s\n", SDL_GetError());
        return 1;
    }
    Renderer renderer;
    if (!renderer.Init()) {
        printf("No se pudo inicializar Renderer\n");
        SDL_Quit();
        return 1;
    }
    // Inicializar miniaudio
    ma_result result;
    ma_engine engine;
    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        printf("Error al inicializar miniaudio engine\n");
        SDL_Quit();
        return -1;
    }
    const char* sounds[] = {
        "assets/player_shoot.wav",
        "assets/enemy_explosion.wav",
        "assets/player_death.wav"
    };
    int running = 1;
    int sound_idx = 0;
    int repeat = 0;
    Uint32 lastSoundTime = SDL_GetTicks();
    while (running && repeat < 20) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) running = 0;
        }
        // Reproducir sonido cada 1 segundo
        Uint32 now = SDL_GetTicks();
        if (now - lastSoundTime > 1000) {
            printf("Reproduciendo: %s\n", sounds[sound_idx]);
            ma_engine_play_sound(&engine, sounds[sound_idx], NULL);
            sound_idx = (sound_idx + 1) % 3;
            if (sound_idx == 0) repeat++;
            lastSoundTime = now;
        }
        // Dibujar fondo y cuadrado usando Renderer
        renderer.Clear();
        SDL_Renderer* sdlRenderer = renderer.GetSDLRenderer();
        SDL_SetRenderDrawColor(sdlRenderer, 0, 200, 255, 255);
        SDL_FRect rect = {350, 250, 100, 100};
        SDL_RenderFillRect(sdlRenderer, &rect);
        renderer.Present();
        SDL_Delay(16);
    }
    ma_engine_uninit(&engine);
    SDL_Quit();
    return 0;
}
