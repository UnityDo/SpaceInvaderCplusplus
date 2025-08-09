#include <SDL3/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Test SDL3 Básico..." << std::endl;
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Error al inicializar SDL: " << SDL_GetError() << std::endl;
        return 1;
    }
    
    std::cout << "SDL inicializado correctamente!" << std::endl;
    
    SDL_Window* window = SDL_CreateWindow("Test Básico", 640, 480, 0);
    if (!window) {
        std::cout << "Error al crear ventana: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    
    std::cout << "Ventana creada!" << std::endl;
    
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        std::cout << "Error al crear renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    
    std::cout << "Renderer creado! Mostrando ventana por 3 segundos..." << std::endl;
    
    // Limpiar con color azul
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);
    
    // Dibujar un rectángulo rojo
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_FRect rect = {250, 200, 140, 80};
    SDL_RenderFillRect(renderer, &rect);
    
    SDL_RenderPresent(renderer);
    
    SDL_Delay(3000);
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    std::cout << "Test completado exitosamente!" << std::endl;
    return 0;
}
