@echo off
REM Compilar el juego principal con los flags y rutas exactos

g++ main.cpp Game.cpp Player.cpp Enemy.cpp Bullet.cpp EnemyManager.cpp CollisionManager.cpp Renderer.cpp InputManager.cpp ParticleSystem.cpp TextRenderer.cpp AudioManager.cpp -o Game.exe -Ilibs\SDL3-3.2.18\x86_64-w64-mingw32\include -Ilibs\SDL3-3.2.18\x86_64-w64-mingw32\include\SDL3 -Ilibs\SDL3_ttf-devel-3.2.2-mingw\x86_64-w64-mingw32\include -Llibs\SDL3-3.2.18\x86_64-w64-mingw32\lib -Llibs\SDL3_ttf-devel-3.2.2-mingw\x86_64-w64-mingw32\lib -lSDL3 -lSDL3_ttf -static-libgcc -static-libstdc++

echo Compilación finalizada. Ejecuta Game.exe