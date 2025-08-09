@echo off
REM Compila y ejecuta el test de miniaudio + SDL3 usando tu clase Renderer
cd /d "%~dp0"
g++ test_miniaudio_sdl.cpp Renderer.cpp -o test_miniaudio_sdl.exe ^
  -Ilibs\SDL3-3.2.18\x86_64-w64-mingw32\include ^
  -Llibs\SDL3-3.2.18\x86_64-w64-mingw32\lib ^
  -lSDL3 -static-libgcc -static-libstdc++
if errorlevel 1 (
  echo Error de compilacion
  pause
  exit /b 1
)
start "Test Miniaudio SDL" test_miniaudio_sdl.exe
