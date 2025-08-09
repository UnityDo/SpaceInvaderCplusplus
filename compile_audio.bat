@echo off
echo 🔊 === COMPILANDO SPACE INVADERS CON AUDIO BEEP ===
echo.
echo ⚙️ Compilando con sonidos reales de Windows...

g++ main.cpp Game.cpp Player.cpp Enemy.cpp Bullet.cpp EnemyManager.cpp CollisionManager.cpp Renderer.cpp InputManager.cpp ParticleSystem.cpp TextRenderer.cpp AudioManagerBeep.cpp -o SpaceAudio.exe -Ilibs\SDL3-3.2.18\x86_64-w64-mingw32\include -Ilibs\SDL3-3.2.18\x86_64-w64-mingw32\include\SDL3 -Ilibs\SDL3_ttf-devel-3.2.2-mingw\x86_64-w64-mingw32\include -Llibs\SDL3-3.2.18\x86_64-w64-mingw32\lib -Llibs\SDL3_ttf-devel-3.2.2-mingw\x86_64-w64-mingw32\lib -lSDL3 -lSDL3_ttf -static-libgcc -static-libstdc++

if %ERRORLEVEL% == 0 (
    echo.
    echo ✅ ¡COMPILACIÓN EXITOSA!
    echo 📁 Ejecutable: SpaceAudio.exe
    echo.
    echo 🔊 SONIDOS IMPLEMENTADOS:
    echo    🎯 Disparo: 900Hz x 80ms (agudo)
    echo    💥 Explosión: 300Hz x 200ms (grave)
    echo    ☠️ Muerte: 150Hz x 500ms (dramático)
    echo.
    echo 🎮 Para jugar: SpaceAudio.exe
    echo 🎵 Para jugar con info: play_audio.bat
    echo.
) else (
    echo.
    echo ❌ Error en la compilación
    echo 💡 Verifica que todas las librerías SDL3 estén en su lugar
    echo.
)

pause
