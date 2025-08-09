@echo off
REM Compila y ejecuta el test de miniaudio en una ventana mínima
g++ test_miniaudio.cpp -o test_miniaudio.exe
REM Ejecuta el test en una ventana separada
start "Test Miniaudio" cmd /c test_miniaudio.exe
