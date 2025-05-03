#ifndef GURI2D_HPP
#define GURI2D_HPP

#include "canvas.hpp"
#include "physics.hpp"
#include "sound.hpp"
#include "input.hpp"

namespace Guri2D {
    // Guri2D motoru
    class Guri2D {
    private:
        std::shared_ptr<CanvasClient> canvas;
        std::shared_ptr<PhysicsClient> physics;
        std::shared_ptr<SoundClient> sound;
        std::shared_ptr<InputClient> input;
        
    public:
        Guri2D()
            : canvas(std::make_shared<CanvasClient>(std::make_shared<CanvasManager>())),
              physics(std::make_shared<PhysicsClient>(std::make_shared<PhysicsManager>())),
              sound(std::make_shared<SoundClient>(std::make_shared<SoundManager>())),
              input(std::make_shared<InputClient>(std::make_shared<InputManager>())) {}
        
        // Kanvas yönetimi
        void createCanvas(int width = 800, int height = 600) {
            canvas->create();
            canvas->setSize(width, height);
        }
        
        void loadCanvas() {
            canvas->load();
        }
        
        // Fizik yönetimi
        void addPhysicsObject(std::shared_ptr<PhysicsObject> object) {
            physics->addObject(object);
        }
        
        void updatePhysics(float deltaTime) {
            physics->update(deltaTime);
        }
        
        // Ses yönetimi
        void addSound(const std::string& name, const std::string& path) {
            sound->addSound(name, path);
        }
        
        void playSound(const std::string& name) {
            sound->play(name);
        }
        
        void stopSound(const std::string& name) {
            sound->stop(name);
        }
        
        // Girdi yönetimi
        void onKeyDown(int key, const std::function<void()>& callback) {
            input->onKeyDown(key, callback);
        }
        
        void onKeyUp(int key, const std::function<void()>& callback) {
            input->onKeyUp(key, callback);
        }
        
        void onMouseMove(const std::function<void(int, int)>& callback) {
            input->onMouseMove(callback);
        }
        
        void updateInput() {
            input->update();
        }
        
        // Motor durumu
        bool isRunning() const {
            return canvas->isVisible();
        }
        
        void update(float deltaTime) {
            updatePhysics(deltaTime);
            updateInput();
        }
    };
    
    // Kanvas oluşturma
    void createCanvas(int width = 800, int height = 600) {
        auto guri = std::make_shared<Guri2D>();
        guri->createCanvas(width, height);
    }
    
    // Kanvas yükleme
    void loadCanvas() {
        auto guri = std::make_shared<Guri2D>();
        guri->loadCanvas();
    }
}

#endif // GURI2D_HPP
