@echo off
REM Compila el juego SpaceAudio.exe con soporte miniaudio
cd /d "c:\Users\Usuario\Documents\UnReal\Clases\Preguntas\CPlusplus_Games\Game_10"
g++ main.cpp Game.cpp Player.cpp Enemy.cpp Bullet.cpp EnemyManager.cpp CollisionManager.cpp Renderer.cpp InputManager.cpp ParticleSystem.cpp TextRenderer.cpp AudioManagerBeep.cpp AudioManagerMiniaudio.cpp -o SpaceAudio.exe ^
  -Ilibs\SDL3-3.2.18\x86_64-w64-mingw32\include ^
  -Ilibs\SDL3-3.2.18\x86_64-w64-mingw32\include\SDL3 ^
  -Ilibs\SDL3_ttf-devel-3.2.2-mingw\x86_64-w64-mingw32\include ^
  -Llibs\SDL3-3.2.18\x86_64-w64-mingw32\lib ^
  -Llibs\SDL3_ttf-devel-3.2.2-mingw\x86_64-w64-mingw32\lib ^
  -lSDL3 -lSDL3_ttf -static-libgcc -static-libstdc++
echo Compilación finalizada. Ejecutable: SpaceAudio.exe
