#ifndef GURI2D_INPUT_HPP
#define GURI2D_INPUT_HPP

#include <string>
#include <memory>
#include <map>
#include <functional>

namespace Guri2D {
    // Tuş durumu
    enum class KeyState {
        Released,
        Pressed,
        Held
    };
    
    // Fare durumu
    enum class MouseState {
        Released,
        Pressed,
        Moved
    };
    
    // Girdi yöneticisi
    class InputManager {
    private:
        std::map<int, KeyState> keyStates;
        std::map<int, MouseState> mouseStates;
        
        // Olay yöneticileri
        std::map<int, std::function<void()>> keyDownCallbacks;
        std::map<int, std::function<void()>> keyUpCallbacks;
        std::map<int, std::function<void(int, int)>> mouseMoveCallbacks;
        
    public:
        // Tuş durumu
        KeyState getKeyState(int key) {
            if (keyStates.find(key) != keyStates.end()) {
                return keyStates[key];
            }
            return KeyState::Released;
        }
        
        // Fare durumu
        MouseState getMouseState(int button) {
            if (mouseStates.find(button) != mouseStates.end()) {
                return mouseStates[button];
            }
            return MouseState::Released;
        }
        
        // Tuş olayları
        void onKeyDown(int key, const std::function<void()>& callback) {
            keyDownCallbacks[key] = callback;
        }
        
        void onKeyUp(int key, const std::function<void()>& callback) {
            keyUpCallbacks[key] = callback;
        }
        
        void onMouseMove(const std::function<void(int, int)>& callback) {
            mouseMoveCallbacks[0] = callback; // 0 represents any button
        }
        
        // Girdi güncelleme
        void update() {
            // Tuş olayları
            for (auto& pair : keyStates) {
                if (pair.second == KeyState::Pressed) {
                    if (keyDownCallbacks.find(pair.first) != keyDownCallbacks.end()) {
                        keyDownCallbacks[pair.first]();
                    }
                    pair.second = KeyState::Held;
                }
            }
            
            // Fare olayları
            for (auto& pair : mouseStates) {
                if (pair.second == MouseState::Pressed) {
                    if (mouseMoveCallbacks.find(pair.first) != mouseMoveCallbacks.end()) {
                        mouseMoveCallbacks[pair.first](0, 0); // Mouse position
                    }
                    pair.second = MouseState::Moved;
                }
            }
        }
    };
    
    // Girdi istemcisi
    class InputClient {
    private:
        std::shared_ptr<InputManager> manager;
        
    public:
        InputClient(std::shared_ptr<InputManager> manager)
            : manager(manager) {}
        
        KeyState getKeyState(int key) {
            return manager->getKeyState(key);
        }
        
        MouseState getMouseState(int button) {
            return manager->getMouseState(button);
        }
        
        void onKeyDown(int key, const std::function<void()>& callback) {
            manager->onKeyDown(key, callback);
        }
        
        void onKeyUp(int key, const std::function<void()>& callback) {
            manager->onKeyUp(key, callback);
        }
        
        void onMouseMove(const std::function<void(int, int)>& callback) {
            manager->onMouseMove(callback);
        }
        
        void update() {
            manager->update();
        }
    };
}

#endif // GURI2D_INPUT_HPP
