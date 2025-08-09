#include <SDL3/SDL.h>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("No se pudo inicializar SDL: %s", SDL_GetError());
        system("pause");
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow("Prueba Cubo SDL3", 640, 480, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    bool running = true;
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) running = false;
        }
        SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
        SDL_RenderClear(renderer);
        // Dibuja un cubo azul
        SDL_FRect cube = {270, 190, 100, 100};
        SDL_SetRenderDrawColor(renderer, 0, 120, 255, 255);
        SDL_RenderFillRect(renderer, &cube);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderRect(renderer, &cube);
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
