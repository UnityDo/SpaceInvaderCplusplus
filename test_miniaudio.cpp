// Test miniaudio con ventana mínima Win32
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include <stdio.h>
#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (msg == WM_DESTROY) PostQuitMessage(0);
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int main() {
    // Crear ventana mínima
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = L"MiniAudioTestWnd";
    RegisterClass(&wc);
    HWND hwnd = CreateWindowW(L"MiniAudioTestWnd", L"Test Miniaudio", WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, 320, 120, NULL, NULL, wc.hInstance, NULL);
    ShowWindow(hwnd, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    const char* sounds[] = {
        "assets/player_shoot.wav",
        "assets/enemy_explosion.wav",
        "assets/player_death.wav"
    };
    ma_result result;
    ma_engine engine;
    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        printf("Error al inicializar miniaudio engine\n");
        return -1;
    }
    for (int repeat = 0; repeat < 20; ++repeat) {
        printf("Repetición %d/20\n", repeat+1);
        for (int i = 0; i < 3; ++i) {
            printf("Reproduciendo: %s\n", sounds[i]);
            result = ma_engine_play_sound(&engine, sounds[i], NULL);
            if (result != MA_SUCCESS) {
                printf("Error al reproducir %s\n", sounds[i]);
            }
            Sleep(1000); // Espera 1 segundo entre sonidos
        }
    }
    printf("Fin de prueba. Cierra la ventana para salir.\n");
    // Esperar a que el usuario cierre la ventana
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    ma_engine_uninit(&engine);
    return 0;
}
