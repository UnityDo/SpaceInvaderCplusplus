@echo off
color 0a
echo ========================================
echo           SPACE INVADERS
echo         ¡Juego Completo!
echo ========================================
echo.
echo CONTROLES:
echo   ← → : Mover nave (circulo verde)
echo   ESPACIO : Disparar balas
echo   ESC : Salir del juego
echo.
echo OBJETIVO:
echo   Destruye a todos los enemigos rojos
echo   antes de que lleguen hasta abajo
echo.
echo CARACTERÍSTICAS:
echo   ✓ Movimiento fluido del jugador
echo   ✓ Sistema de disparos
echo   ✓ Enemigos en formación
echo   ✓ Colisiones funcionando
echo   ✓ Enemigos se mueven en grupo
echo   ✓ Patrón clásico Space Invaders
echo.
echo Presiona cualquier tecla para jugar...
pause >nul
cls
Game.exe
echo.
echo ¡Gracias por jugar!
pause
