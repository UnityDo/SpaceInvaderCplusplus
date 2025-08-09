@echo off
echo Compilando BasicTest...
g++ BasicTest.cpp -o BasicTest.exe -Ilibs\SDL3-3.2.18\x86_64-w64-mingw32\include -Ilibs\SDL3-3.2.18\x86_64-w64-mingw32\include\SDL3 -Llibs\SDL3-3.2.18\x86_64-w64-mingw32\lib -lSDL3 -static-libgcc -static-libstdc++
if exist BasicTest.exe (
    echo Compilacion exitosa! Ejecutando...
    BasicTest.exe
) else (
    echo Error en compilacion!
)
pause
