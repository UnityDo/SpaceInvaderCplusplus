#include <SDL3/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Test Simple SDL3 - Dibujando cuadrado..." << std::endl;
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Error SDL: " << SDL_GetError() << std::endl;
        return 1;
    }
    
    std::cout << "SDL OK!" << std::endl;
    
    SDL_Window* window = SDL_CreateWindow("Test Cuadrado", 640, 480, 0);
    if (!window) {
        std::cout << "Error ventana: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        std::cout << "Error renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    
    std::cout << "Ventana y renderer OK! Presiona cualquier tecla para cerrar..." << std::endl;
    
    bool running = true;
    SDL_Event event;
    
    while (running) {
        // Procesar eventos
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT || event.type == SDL_EVENT_KEY_DOWN) {
                running = false;
            }
        }
        
        // Limpiar pantalla (negro)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        // Dibujar cuadrado rojo en el centro
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_FRect rect = {270, 190, 100, 100}; // x, y, ancho, alto
        SDL_RenderFillRect(renderer, &rect);
        
        // Mostrar en pantalla
        SDL_RenderPresent(renderer);
        
        SDL_Delay(16); // ~60 FPS
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Test completado" << std::endl;
    return 0;
}
