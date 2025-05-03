#ifndef GURI2D_PHYSICS_HPP
#define GURI2D_PHYSICS_HPP

#include <string>
#include <memory>
#include <vector>
#include <functional>

namespace Guri2D {
    // Fizik nesnesi
    class PhysicsObject {
    public:
        float x;
        float y;
        float velocityX;
        float velocityY;
        float accelerationX;
        float accelerationY;
        float mass;
        float friction;
        
        PhysicsObject(float x = 0, float y = 0, float mass = 1.0f)
            : x(x), y(y), mass(mass), friction(0.9f) {}
        
        void update(float deltaTime) {
            // Hız güncelleme
            velocityX += accelerationX * deltaTime;
            velocityY += accelerationY * deltaTime;
            
            // Pozisyon güncelleme
            x += velocityX * deltaTime;
            y += velocityY * deltaTime;
            
            // Sürükleme uygulama
            velocityX *= friction;
            velocityY *= friction;
        }
        
        void applyForce(float forceX, float forceY) {
            accelerationX += forceX / mass;
            accelerationY += forceY / mass;
        }
    };
    
    // Fizik yöneticisi
    class PhysicsManager {
    private:
        std::vector<std::shared_ptr<PhysicsObject>> objects;
        float gravity;
        float deltaTime;
        
    public:
        PhysicsManager(float gravity = 9.81f)
            : gravity(gravity), deltaTime(0.0f) {}
        
        // Nesne ekleme
        void addObject(std::shared_ptr<PhysicsObject> object) {
            objects.push_back(object);
        }
        
        // Fizik güncelleme
        void update(float deltaTime) {
            this->deltaTime = deltaTime;
            
            for (auto& object : objects) {
                // Yerçekimi uygulama
                object->applyForce(0, gravity * object->mass);
                
                // Nesne güncelleme
                object->update(deltaTime);
            }
        }
        
        // Çarpışma kontrolü
        bool checkCollision(std::shared_ptr<PhysicsObject> obj1, std::shared_ptr<PhysicsObject> obj2) {
            float distance = std::sqrt(
                std::pow(obj1->x - obj2->x, 2) +
                std::pow(obj1->y - obj2->y, 2)
            );
            
            return distance < 1.0f; // Simple collision detection
        }
    };
    
    // Fizik istemcisi
    class PhysicsClient {
    private:
        std::shared_ptr<PhysicsManager> manager;
        
    public:
        PhysicsClient(std::shared_ptr<PhysicsManager> manager)
            : manager(manager) {}
        
        void addObject(std::shared_ptr<PhysicsObject> object) {
            manager->addObject(object);
        }
        
        void update(float deltaTime) {
            manager->update(deltaTime);
        }
        
        bool checkCollision(std::shared_ptr<PhysicsObject> obj1, std::shared_ptr<PhysicsObject> obj2) {
            return manager->checkCollision(obj1, obj2);
        }
    };
}

#endif // GURI2D_PHYSICS_HPP
