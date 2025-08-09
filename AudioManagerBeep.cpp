#include "AudioManagerBeep.h"
#include <thread>
#include <algorithm>

AudioManagerBeep::AudioManagerBeep() 
    : isInitialized(false), masterVolume(0.7f) {
}

AudioManagerBeep::~AudioManagerBeep() {
    Shutdown();
}

bool AudioManagerBeep::Initialize() {
    if (isInitialized) {
        return true;
    }
    
    std::cout << "🔊 Inicializando AudioManager BEEP (Windows)..." << std::endl;
    
    isInitialized = true;
    std::cout << "✅ AudioManager BEEP inicializado correctamente" << std::endl;
    std::cout << "   Modo: Sonidos del sistema Windows" << std::endl;
    
    return true;
}

void AudioManagerBeep::Shutdown() {
    if (!isInitialized) {
        return;
    }
    
    std::cout << "🔊 Cerrando AudioManager BEEP..." << std::endl;
    soundEffects.clear();
    isInitialized = false;
    std::cout << "✅ AudioManager BEEP cerrado" << std::endl;
}

bool AudioManagerBeep::LoadSound(const std::string& name, const std::string& filepath) {
    if (!isInitialized) {
        std::cout << "⚠️ AudioManager no inicializado" << std::endl;
        return false;
    }
    
    std::cout << "📂 Registrando sonido BEEP: " << name << std::endl;
    soundEffects[name] = true;
    std::cout << "✅ Sonido '" << name << "' registrado" << std::endl;
    
    return true;
}

void AudioManagerBeep::PlaySound(const std::string& name, float volume) {
    if (!isInitialized) {
        return;
    }
    
    auto it = soundEffects.find(name);
    if (it == soundEffects.end()) {
        std::cout << "⚠️ Sonido '" << name << "' no encontrado" << std::endl;
        return;
    }
    
    float finalVolume = masterVolume * volume;
    if (finalVolume < 0.1f) {
        return; // Muy bajo para reproducir
    }
    
    // Reproducir sonido específico usando Beep de Windows
    int frequency = 800;  // Frecuencia por defecto
    int duration = 100;   // Duración por defecto
    
    // Sonidos específicos para Space Invaders
    if (name == "player_shoot") {
        frequency = 900;  // Sonido agudo para disparo
        duration = 80;
    } else if (name == "enemy_explosion") {
        frequency = 300;  // Sonido grave para explosión
        duration = 200;
    } else if (name == "player_death") {
        frequency = 150;  // Sonido muy grave para muerte
        duration = 500;
    }
    // Sonidos originales de Pong (compatibilidad)
    else if (name == "paddle_hit") {
        frequency = 800;
        duration = 100;
    } else if (name == "wall_bounce") {
        frequency = 400;
        duration = 150;
    } else if (name == "score") {
        frequency = 600;
        duration = 300;
    } else if (name == "game_start") {
        frequency = 500;
        duration = 200;
    }
    
    // Ajustar duración por volumen
    duration = (int)(duration * finalVolume);
    
    std::cout << "🔊 ¡BEEP! " << name << " (" << frequency << "Hz, " << duration << "ms)" << std::endl;
    
    // Reproducir en hilo separado para no bloquear el juego
    std::thread([frequency, duration]() {
        Beep(frequency, duration);
    }).detach();
}

void AudioManagerBeep::SetMasterVolume(float volume) {
    masterVolume = (std::max)(0.0f, (std::min)(1.0f, volume));
    // No se requiere algoritmo adicional aquí, solo se asegura que el volumen esté en [0,1]    
    std::cout << "🔊 Volumen maestro BEEP: " << (int)(masterVolume * 100) << "%" << std::endl;
}

float AudioManagerBeep::GetMasterVolume() const {
    return masterVolume;
}

bool AudioManagerBeep::IsInitialized() const {
    return isInitialized;
}

void AudioManagerBeep::ShowDebugInfo() const {
    std::cout << "\n🔊 === AUDIO BEEP DEBUG INFO ===" << std::endl;
    std::cout << "Inicializado: " << (isInitialized ? "✅" : "❌") << std::endl;
    std::cout << "Volumen maestro: " << (int)(masterVolume * 100) << "%" << std::endl;
    std::cout << "Sonidos registrados: " << soundEffects.size() << std::endl;
    
    for (const auto& pair : soundEffects) {
        std::cout << "  - " << pair.first << " (BEEP)" << std::endl;
    }
    
    std::cout << "Nota: Usando Beep() de Windows para sonidos reales" << std::endl;
    std::cout << "===================================" << std::endl;
}
