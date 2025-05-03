#ifndef GURI2D_SOUND_HPP
#define GURI2D_SOUND_HPP

#include <string>
#include <memory>
#include <map>
#include <functional>

namespace Guri2D {
    // Ses nesnesi
    class Sound {
    public:
        std::string path;
        float volume;
        bool isLooping;
        
        Sound(const std::string& path)
            : path(path), volume(1.0f), isLooping(false) {}
        
        void play() {
            // Ses oynatma
        }
        
        void stop() {
            // Ses durdurma
        }
        
        void setVolume(float volume) {
            this->volume = volume;
        }
        
        void setLooping(bool isLooping) {
            this->isLooping = isLooping;
        }
    };
    
    // Ses yöneticisi
    class SoundManager {
    private:
        std::map<std::string, std::shared_ptr<Sound>> sounds;
        
    public:
        // Ses ekleme
        void addSound(const std::string& name, const std::string& path) {
            sounds[name] = std::make_shared<Sound>(path);
        }
        
        // Ses oynatma
        void play(const std::string& name) {
            if (sounds.find(name) != sounds.end()) {
                sounds[name]->play();
            }
        }
        
        // Ses durdurma
        void stop(const std::string& name) {
            if (sounds.find(name) != sounds.end()) {
                sounds[name]->stop();
            }
        }
        
        // Ses ayarları
        void setVolume(const std::string& name, float volume) {
            if (sounds.find(name) != sounds.end()) {
                sounds[name]->setVolume(volume);
            }
        }
        
        void setLooping(const std::string& name, bool isLooping) {
            if (sounds.find(name) != sounds.end()) {
                sounds[name]->setLooping(isLooping);
            }
        }
    };
    
    // Ses istemcisi
    class SoundClient {
    private:
        std::shared_ptr<SoundManager> manager;
        
    public:
        SoundClient(std::shared_ptr<SoundManager> manager)
            : manager(manager) {}
        
        void addSound(const std::string& name, const std::string& path) {
            manager->addSound(name, path);
        }
        
        void play(const std::string& name) {
            manager->play(name);
        }
        
        void stop(const std::string& name) {
            manager->stop(name);
        }
        
        void setVolume(const std::string& name, float volume) {
            manager->setVolume(name, volume);
        }
        
        void setLooping(const std::string& name, bool isLooping) {
            manager->setLooping(name, isLooping);
        }
    };
}

#endif // GURI2D_SOUND_HPP
