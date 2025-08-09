@echo off
REM Compilar Space Invaders con Audio BEEP - Versión rápida

echo Compilando SpaceAudio.exe...

g++ main.cpp Game.cpp Player.cpp Enemy.cpp Bullet.cpp EnemyManager.cpp CollisionManager.cpp Renderer.cpp InputManager.cpp ParticleSystem.cpp TextRenderer.cpp AudioManagerBeep.cpp -o SpaceAudio.exe -Ilibs\SDL3-3.2.18\x86_64-w64-mingw32\include -Ilibs\SDL3-3.2.18\x86_64-w64-mingw32\include\SDL3 -Ilibs\SDL3_ttf-devel-3.2.2-mingw\x86_64-w64-mingw32\include -Llibs\SDL3-3.2.18\x86_64-w64-mingw32\lib -Llibs\SDL3_ttf-devel-3.2.2-mingw\x86_64-w64-mingw32\lib -lSDL3 -lSDL3_ttf -static-libgcc -static-libstdc++

if %ERRORLEVEL% == 0 (
    echo ✅ Listo! SpaceAudio.exe
) else (
    echo ❌ Error compilando
)
