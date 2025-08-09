# Space Invaders con Sistema de Audio 🎮🔊

## Nuevas Características de Audio

### Sonidos Implementados

1. **🎯 Disparo del Jugador** (`player_shoot.wav`)
   - Se reproduce cada vez que presionas SPACE para disparar
   - Volumen: 70%
   - Basado en el sonido `wall_bounce.wav` de Game_06

2. **💥 Explosión de Enemigos** (`enemy_explosion.wav`)
   - Se reproduce cuando una bala del jugador impacta un enemigo
   - Volumen: 80%
   - Sincronizado con las partículas de explosión
   - Basado en el sonido `paddle_hit.wav` de Game_06

3. **☠️ Muerte del Jugador** (`player_death.wav`)
   - Se reproduce cuando una bala enemiga impacta al jugador
   - Volumen: 90%
   - Acompañado de explosión de partículas
   - Basado en el sonido `score.wav` de Game_06

### Sistema de Audio

- **AudioManager**: Sistema completo de gestión de audio adaptado de Game_06
- **Inicialización automática**: El audio se inicializa al arrancar el juego
- **Control de volumen**: Cada sonido tiene su propio nivel de volumen
- **Gestión de memoria**: Los recursos de audio se liberan correctamente al cerrar

### Compilación

```bash
compile_spaceinvaders.bat
```

### Estructura de Archivos de Audio

```
Game_10/
├── assets/
│   ├── player_shoot.wav     # Sonido de disparo
│   ├── enemy_explosion.wav  # Sonido de explosión enemigo
│   └── player_death.wav     # Sonido de muerte jugador
├── AudioManager.h           # Header del sistema audio
├── AudioManager.cpp         # Implementación del audio
└── SpaceInvaders.exe        # Ejecutable del juego
```

### Integración Técnica

1. **Game.h/Game.cpp**: Agregado AudioManager como miembro privado
2. **CollisionManager**: Reproduce sonidos en las colisiones correspondientes
3. **Input Handling**: Sonido de disparo integrado en el manejo de eventos
4. **Memory Management**: AudioManager incluido en constructor/destructor

### Controles

- **←/→**: Mover jugador
- **SPACE**: Disparar (con sonido)
- **ESC**: Salir del juego

### Características del Juego

- **Enemigos rápidos**: Movimiento acelerado (150 velocidad, 0.3s intervalos)
- **Sistema de vidas**: 3 vidas con explosiones y sonido al morir
- **Puntuación**: +10 puntos por enemigo destruido
- **Partículas**: Explosiones visuales sincronizadas con audio
- **Game Over**: Pantalla final con puntuación total
- **Pantalla de Victoria**: "¡VICTORIA!" + "Gracias por jugar" al eliminar todos los enemigos

---

*Basado en el sistema de audio de Game_06 (Pong) y adaptado para Space Invaders* 🚀
