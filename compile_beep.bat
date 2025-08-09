@echo off
REM Compilar Space Invaders con sistema de audio BEEP (sonidos reales)

echo Compilando Space Invaders con efectos BEEP de Windows...

g++ main.cpp Game.cpp Player.cpp Enemy.cpp Bullet.cpp EnemyManager.cpp CollisionManager.cpp Renderer.cpp InputManager.cpp ParticleSystem.cpp TextRenderer.cpp AudioManagerBeep.cpp -o SpaceInvadersBeep.exe -Ilibs\SDL3-3.2.18\x86_64-w64-mingw32\include -Ilibs\SDL3-3.2.18\x86_64-w64-mingw32\include\SDL3 -Ilibs\SDL3_ttf-devel-3.2.2-mingw\x86_64-w64-mingw32\include -Llibs\SDL3-3.2.18\x86_64-w64-mingw32\lib -Llibs\SDL3_ttf-devel-3.2.2-mingw\x86_64-w64-mingw32\lib -lSDL3 -lSDL3_ttf -static-libgcc -static-libstdc++

if %ERRORLEVEL% == 0 (
    echo ✅ Compilación exitosa! Space Invaders con sonidos BEEP reales listo.
    echo 🔊 SONIDOS IMPLEMENTADOS:
    echo    - Disparo jugador: 900Hz, 80ms
    echo    - Explosión enemigo: 300Hz, 200ms  
    echo    - Muerte jugador: 150Hz, 500ms
    echo 🎮 Ejecuta: SpaceInvadersBeep.exe
) else (
    echo ❌ Error en la compilación
)

pause
