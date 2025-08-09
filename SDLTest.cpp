#include <SDL3/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Intentando inicializar SDL..." << std::endl;
    
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Error completo: " << SDL_GetError() << std::endl;
        system("pause");
        return 1;
    }
    
    std::cout << "SDL inicializado correctamente!" << std::endl;
    
    SDL_Window* window = SDL_CreateWindow("Test", 640, 480, 0);
    if (!window) {
        std::cout << "Error creando ventana: " << SDL_GetError() << std::endl;
        SDL_Quit();
        system("pause");
        return 1;
    }
    
    std::cout << "Ventana creada correctamente!" << std::endl;
    SDL_Delay(2000);
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
