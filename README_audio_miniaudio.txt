# Instrucciones para integrar miniaudio

1. Asegúrate de que miniaudio.h esté en la carpeta del proyecto (ya descargado).
2. Los archivos .wav deben estar en la carpeta assets/ dentro de Game_10.
3. AudioManagerMiniaudio.{h,cpp} implementa la carga y reproducción de sonidos .wav usando miniaudio.
4. Game.cpp ya está modificado para usar AudioManagerMiniaudio y cargar los sonidos:
   - player_shoot.wav
   - enemy_explosion.wav
   - player_death.wav

# Compilación

Agrega miniaudio.h y AudioManagerMiniaudio.cpp/h a tu build. Ejemplo de línea de compilación:

```
g++ Game.cpp AudioManagerMiniaudio.cpp ... -o Game.exe -lSDL3 ...
```

# Notas
- Si hay errores de símbolos duplicados, asegúrate de que solo un archivo tenga #define MINIAUDIO_IMPLEMENTATION antes de incluir miniaudio.h.
- Si quieres añadir más sonidos, llama a LoadSound con el nombre y ruta del .wav.
- El audio ahora será grabable por NVIDIA Record y otros programas.
